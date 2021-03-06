//---------------------------------------------------------------------------//
/*!
 * \file Sphere.cc
 */
//---------------------------------------------------------------------------//

#include "Sphere.hh"

#include <cassert>

namespace ExaMPM
{
//---------------------------------------------------------------------------//
// Constructor. Bounds give (-x,+x,-y,+y,-z,+z).
Sphere::Sphere( const std::array<double,3>& center, const double radius )
    : d_center( center )
    , d_radius( radius )
{ /* ... */ }

//---------------------------------------------------------------------------//
// Determine if a particle is in the geometry.
bool Sphere::particleInGeometry( const Particle& p ) const
{
    std::array<double,3> ref_p = { p.r[0] - d_center[0],
                                   p.r[1] - d_center[1],
                                   p.r[2] - d_center[2] };

    return
        ( ref_p[0]*ref_p[0] + ref_p[1]*ref_p[1] + ref_p[2]*ref_p[2] ) <=
        d_radius*d_radius;
}

//---------------------------------------------------------------------------//

} // end namespace ExaMPM

//---------------------------------------------------------------------------//
// end Sphere.cc
//---------------------------------------------------------------------------//
