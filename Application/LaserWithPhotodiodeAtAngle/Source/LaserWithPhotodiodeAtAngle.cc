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
	static constexpr double kParticleBoxXDimensionInMeters = .001;
	static constexpr double kParticleBoxYDimensionInMeters = .001;
	static constexpr double kParticleBoxZDimensionInMeters = .001;
	static constexpr double kParticleBoxVolumnInMetersCubed =
		kParticleBoxXDimensionInMeters *
		kParticleBoxYDimensionInMeters *
		kParticleBoxZDimensionInMeters;

	/* Particle Types */
	static constexpr double kIndexOfRefractionReal = 1.0;
	static constexpr double kIndexOfRefractionImaginary = 1.0;
	static constexpr double kPM2_5MassInKilograms = .001;
	static constexpr double kPM10MassInKilograms = .01;
	static constexpr double kPM2_5ConcentrationInMolPerMeterCubed = .45;
	static constexpr double kPM10ConcentrationInMolPerMeterCubed = .23;
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
