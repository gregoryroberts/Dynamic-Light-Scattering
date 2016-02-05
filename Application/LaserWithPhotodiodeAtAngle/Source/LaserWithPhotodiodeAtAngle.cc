#include "Common/Common.h"
#include "Math/Complex.h"
#include "Math/Constant.h"
#include "Math/Geometry/DotProduct.h"
#include "Math/Geometry/PlaneAngle.h"
#include "Math/Point.h"
#include "Physics/Laser.h"
#include "Physics/BrownianUpdate.h"
#include "Physics/ParticleBox.h"
#include "Physics/ParticleType.h"
#include "Physics/Photodiode.h"
#include "Utils/ReadFile.h"

#include <iostream>
// private namespace for configuration
// todo: need a better way to handle the configuration
namespace {

struct Configuration {
	/* Laser */
	static constexpr double kLaserSigmaInMeters = 0.125e-3;
	static constexpr double kLaserPositionX = 0.0;
	static constexpr double kLaserPositionY = 0.0;
	static constexpr double kLaserPositionZ = 0.0;
	static constexpr double kLaserMaxIntensity = 1e-3;

	/* Particle Box Dimensions */
	static constexpr double kParticleBoxXDimensionInMeters = 0.25e-3;
	static constexpr double kParticleBoxYDimensionInMeters = 0.25e-3;
	static constexpr double kParticleBoxZDimensionInMeters = 0.25e-3;
	static constexpr double kParticleBoxVolumnInMetersCubed =
		kParticleBoxXDimensionInMeters *
		kParticleBoxYDimensionInMeters *
		kParticleBoxZDimensionInMeters;
	static constexpr double kParticleBoxOriginX = -kLaserPositionX / 2.;
	static constexpr double kParticleBoxOriginY = -kLaserPositionY / 2.;
	static constexpr double kParticleBoxOriginZ = 0.0;

	/* Particle Types */
	static constexpr double kIndexOfRefractionReal = 1.5;
	static constexpr double kIndexOfRefractionImaginary = 0.0;

	static constexpr size_t kNumberOfParticles = 2;

	// S02
	static constexpr double kPM2_5KilogramsPerMole = 64.066e-3;
	// ??
	static constexpr double kPM10KilogramsPerMole = 100e-3;

	static constexpr double kPM2_5KilogramsPerMeterCubed = 15e-9;
	static constexpr double kPM10KilogramsPerMeterCubed = 15e-9;

	static constexpr double kPM2_5ConcentrationInMolPerMeterCubed =
		kPM2_5KilogramsPerMeterCubed * ( 1. / kPM2_5KilogramsPerMole );
	static constexpr double kPM10ConcentrationInMolPerMeterCubed =
		kPM10KilogramsPerMeterCubed * ( 1. / kPM10KilogramsPerMole );

	static constexpr double kPM2_5MassInKilograms =
		kPM2_5KilogramsPerMole / DLS::Math::Constant::kAvogadrosNumber;
	static constexpr double kPM10MassInKilograms =
		kPM10KilogramsPerMole / DLS::Math::Constant::kAvogadrosNumber;

	static constexpr size_t kPM2_5ParticleCount =
		static_cast< size_t >(
			kPM2_5ConcentrationInMolPerMeterCubed *
			kParticleBoxVolumnInMetersCubed *
			DLS::Math::Constant::kAvogadrosNumber );
	static constexpr size_t kPM10ParticleCount =
		static_cast< size_t >(
			kPM10ConcentrationInMolPerMeterCubed *
			kParticleBoxVolumnInMetersCubed *
			DLS::Math::Constant::kAvogadrosNumber );

	/* Mie Scattering Parameters */
	static constexpr size_t kLambdaInNanometers = 500;
	static constexpr size_t kNumberOfAngles = 99;

	/* Photodiode Parameters */
	// todo: making an assumption that the photodiode is big
	// enough to cover the full area of the light coming in
	// and is equally efficient in all of those angles
	static constexpr double kPhotodiodeCoordinateX = 1e-4;
	static constexpr double kPhotodiodeCoordinateY = kParticleBoxYDimensionInMeters / 2.;
	static constexpr double kPhotodiodeCoordinateZ = 0;

	/* Time Parameters */
	static constexpr double kTimestepInSeconds = 1e-6;
	static constexpr double kTotalTimeInSeconds = 1e-2;

};

} // namespace

int main( int argc, char * argv[] )
{

	using namespace DLS;
	using namespace Math;
	using namespace Physics;

	/* Laser source at the origin beaming out along
	the y-axis.  It has a Gaussian pattern based on
	changes in the x-position and the z-position. */
	Laser laser_source(
		::Configuration::kLaserSigmaInMeters,
		::Configuration::kLaserPositionX,
		::Configuration::kLaserPositionZ,
		::Configuration::kLaserMaxIntensity );

	/* Going to start with just two particle types:
		-- PM2.5
			AND
		-- PM10
	*/
	const ComplexRectangular< double > index_of_refraction(
		::Configuration::kIndexOfRefractionReal,
		::Configuration::kIndexOfRefractionImaginary );
	ParticleType< double > pm2_5 = {
		index_of_refraction,
		::Configuration::kPM2_5MassInKilograms
	};
	ParticleType< double > pm10 = {
		index_of_refraction,
		::Configuration::kPM10MassInKilograms
	};

	char * code_base_path = std::getenv( "DLS_CODE_BASE" );
	std::string code_base_prefix;

	if ( NULL == code_base_path ) {
		printf( "It looks like the code base is not found.  Set the environment variable DLS_CODE_BASE\n" );
		return 1;
	} else {
		code_base_prefix = std::string( code_base_path );
	}

	/* Need a pm 2.5 set of mie scattering angles and
	a set of pm 10 scattering angles. */
	std::string filename_pm2_5 =
		code_base_prefix + "/Data/" +
		"mie_" + std::to_string( ::Configuration::kLambdaInNanometers ) + "_" +
		std::to_string( 2500 ) + "_" + std::to_string( ::Configuration::kNumberOfAngles ) + "_" +
		std::to_string( static_cast< size_t >( ::Configuration::kIndexOfRefractionReal * 10 ) ) + "_" +
		std::to_string( static_cast< size_t >( ::Configuration::kIndexOfRefractionImaginary * 10 ) ) +
		".data";

	std::string filename_pm10 =
		code_base_prefix + "/Data/" +
		"mie_" + std::to_string( ::Configuration::kLambdaInNanometers ) + "_" +
		std::to_string( 10000 ) + "_" + std::to_string( ::Configuration::kNumberOfAngles ) + "_" +
		std::to_string( static_cast< size_t >( ::Configuration::kIndexOfRefractionReal * 10 ) ) + "_" +
		std::to_string( static_cast< size_t >( ::Configuration::kIndexOfRefractionImaginary * 10 ) ) +
		".data";

	std::vector< std::vector< double > > scattering_coefficients( ::Configuration::kNumberOfParticles );

	const Status pm2_5_read_status = Utils::ReadFileFloat(
		filename_pm2_5,
		scattering_coefficients[ 0 ] );
	const Status pm10_read_status = Utils::ReadFileFloat(
		filename_pm10,
		scattering_coefficients[ 1 ] );

	if (
		( Status::Failure == pm2_5_read_status ) ||
		( Status::Failure == pm10_read_status ) ) {
		printf("There was an error loading one of the mie scattering coefficient files\n");
		return 1;
	}

	std::vector< ParticleType< double > > particle_types( {
		pm2_5,
		pm10
	} );

	std::vector< size_t > particle_counts( {
		::Configuration::kPM2_5ParticleCount,
		::Configuration::kPM10ParticleCount
	} );

	const double box_dimensions[ 3 ] = {
		::Configuration::kParticleBoxXDimensionInMeters,
		::Configuration::kParticleBoxYDimensionInMeters,
		::Configuration::kParticleBoxZDimensionInMeters
	};

	const double box_origin[ 3 ] = {
		::Configuration::kParticleBoxOriginX,
		::Configuration::kParticleBoxOriginY,
		::Configuration::kParticleBoxOriginZ
	};

	/* Setup a particle box with both of these particle types */
	ParticleBox particle_box(
		particle_types,
		particle_counts,
		box_dimensions,
		box_origin );

	/* Brownian update functor */
	BrownianUpdate brownian;

	/* Set up the simulation loop */
	const size_t number_of_iterations =
		1 +
		static_cast< size_t >(
			::Configuration::kTotalTimeInSeconds /
			::Configuration::kTimestepInSeconds );


	/* Set up a photodiode */
	Photodiode< double > photodiode;
	photodiode.Drain();

	const double angle_increments = 2 * Math::Constant::kPi / ::Configuration::kNumberOfAngles;

	double accumulated_intensities[ number_of_iterations ];

	double progress_increment = 1.;
	double next_progress_update = progress_increment;

	for ( size_t run = 0; run < number_of_iterations; ++run ) {
		/* First, update the particles in the box */
		particle_box.Update(
			::Configuration::kTimestepInSeconds,
			brownian );

		for (
			size_t type = 0;
			type < ::Configuration::kNumberOfParticles;
			++type ) {

			std::vector< Math::Point3D< double > > & particle_list =
				particle_box.GetLocationList( type );

			for (
				size_t particle = 0;
				particle < particle_list.size();
				++particle ) {

				Math::Point3D< double > particle_coordinate =
					particle_list[ particle ];

				const double initial_intensity = laser_source(
					particle_coordinate.x,
					particle_coordinate.y );

				const double angle = Geometry::PlaneAngleRadians(
					::Configuration::kLaserPositionX,
					particle_coordinate.y,
					::Configuration::kLaserPositionZ,

					particle_coordinate.x,
					particle_coordinate.y,
					particle_coordinate.z,

					::Configuration::kPhotodiodeCoordinateX,
					particle_coordinate.y,
					::Configuration::kPhotodiodeCoordinateZ
				);

				const size_t angle_index =
					static_cast< size_t >( angle / angle_increments );

				const double scattering_coefficient =
					scattering_coefficients[ type ][ angle_index ];

				// todo: have to normalize by distance to
				// observer I think!  Double check on this
				// couldn't this make the intensity go over the
				// initial intensity at the scattering site
				const double scatter_to_observer_x =
					particle_coordinate.x - ::Configuration::kPhotodiodeCoordinateX;
				// by assumption
				const double scatter_to_observer_y = 0;
				const double scatter_to_observer_z =
					particle_coordinate.z - ::Configuration::kPhotodiodeCoordinateZ;

				const double scatter_to_observer_distance =
					sqrt(
						Geometry::DotProduct(
							scatter_to_observer_x,
							scatter_to_observer_y,
							scatter_to_observer_z,
							scatter_to_observer_x,
							scatter_to_observer_y,
							scatter_to_observer_z
						) );
				const double scatter_to_observer_distance_reciprocal =
					1. / scatter_to_observer_distance;

				const double scattered_intensity =
					::Configuration::kLaserMaxIntensity *
					scattering_coefficient *
					scatter_to_observer_distance_reciprocal *
					scatter_to_observer_distance_reciprocal;

				photodiode.IncidentRay( scattered_intensity );

			}
		}

		const double accumulated_intensity = photodiode.Drain();
		accumulated_intensities[ run ] = accumulated_intensity;

		const double progress =
			( 100. * (double) run / (double) number_of_iterations );

		if ( progress > next_progress_update ) {
			printf( "Progress: %g percent\n", progress );
			next_progress_update += progress_increment;
		}

	}

	/* Write out the data */
	std::ofstream output_file("./data3.out");
	if ( output_file.is_open() ) {

		output_file << "[ ";

		for ( size_t run = 0; run < number_of_iterations; ++run ) {
			output_file << accumulated_intensities[ run ];

			if ( run != ( number_of_iterations - 1 ) ) {
				output_file << ", ";
			}


		}

		output_file << " ];" << std::endl;

	}

	output_file.close();

	printf( "Hello, Dynamic Light Scattering\n" );

}
