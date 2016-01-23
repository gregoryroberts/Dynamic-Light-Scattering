#include "Common/Common.h"
#include "Math/Complex.h"
#include "Math/Constant.h"
#include "Physics/Laser.h"
#include "Physics/ParticleBox.h"
#include "Physics/ParticleType.h"

// private namespace for configuration
// todo: need a better way to handle the configuration
namespace {

struct Configuration {
	/* Laser */
	static constexpr double kLaserSigma = 1.0;
	static constexpr double kLaserPositionX = 0.0;
	static constexpr double kLaserPositionY = 0.0;
	static constexpr double kLaserPositionZ = 0.0;
	static constexpr double kLaserMaxIntensity = 1.0;

	/* Particle Box Dimensions */
	static constexpr double kParticleBoxXDimensionInMeters = 1e-3;
	static constexpr double kParticleBoxYDimensionInMeters = 1e-3;
	static constexpr double kParticleBoxZDimensionInMeters = 1e-3;
	static constexpr double kParticleBoxVolumnInMetersCubed =
		kParticleBoxXDimensionInMeters *
		kParticleBoxYDimensionInMeters *
		kParticleBoxZDimensionInMeters;

	/* Particle Types */
	static constexpr double kIndexOfRefractionReal = 1.0;
	static constexpr double kIndexOfRefractionImaginary = 1.0;

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
		::Configuration::kLaserSigma,
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

	/* Setup a particle box with both of these particle types */
	ParticleBox particle_box( particle_types, particle_counts, box_dimensions );

	printf( "Hello, Dynamic Light Scattering\n" );

}
