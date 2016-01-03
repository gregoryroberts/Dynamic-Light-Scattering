The "Data" directory has information on Mie scattering for different indices of refraction and particle sizes.  This is all precomputed and the distance from the scattering site to the receiving element needs to be factored in still (in that the numbers in the files need to be divided by the distance from the scattering site to the observer squared).  The files in here are named as follows:

mie_{wavelength in nanometers}_{particle radius in nanometers}_{number of angle buckets}_{real part of index of refraction times 10}_{imaginary part of index of refraction times 10}.data

wavelength in nanometers: the wavelength of the laser light hitting the particle

particle radius in nanometers: this is the radius of the particle in nanometers (given in nanometers under the assumption there won't be a particle radius in need of sub-nanometer resolution)

number of angle buckets: this basically tells how many numbers are in the file.  There is one number per bucket, which is how finely the 2*pi radians have been broken up to specify the scattering ratio at that angle

real part of index of refraction times 10: real part of the index of refraction for the particle multiplied by 10 so that it can be passed as
an integer in the filename (i.e. - given with resolution down to 0.1)

imaginary part of index of refraction times 10: imaginary part of the index of refraction for the particle multiplied by 10 so that it can be passed as an integer in the filename (i.e. - given with resolution down to .1)

The organization of the file is as follows:

There is single double precision floating point number on each line starting from the ratio for an angle of 0 radians and moving all the way to 2*pi radians: [0, 2*pi).  The number of values in the file are equal to the quantity in the title of the file "number of angle buckets."