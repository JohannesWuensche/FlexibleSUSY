#include "collier.hpp"
#include <limits>

extern "C" {
   // Fortran wrapper routine
   std::complex<double> B0_impl(
         const std::complex<double>*,
         const std::complex<double>*, const std::complex<double>*,
         const double*);
   std::complex<double> C0_impl(
         const std::complex<double>*, const std::complex<double>*, const std::complex<double>*,
         const std::complex<double>*, const std::complex<double>*, const std::complex<double>*,
         const double*);
   std::complex<double> C00_impl(
         const std::complex<double>*, const std::complex<double>*, const std::complex<double>*,
         const std::complex<double>*, const std::complex<double>*, const std::complex<double>*,
         const double*);
}

//namespace collier {
   // C++ wrapper with non-pointer parameter
   std::complex<double> Collier::B0(
         std::complex<double> p10_in,
         std::complex<double> m02_in, std::complex<double> m12_in,
         double scl2_in) noexcept {

      /* Non-vanishing imaginary parts of momentum invariants are not yet
       * suppoted by the current version (1.2.3) of COLLIER. */
      const std::complex<double> p10 (p10_in.real(), 0.);
      const std::complex<double> m02 = m02_in;
      const std::complex<double> m12 = m12_in;
      double scl2 = scl2_in;

      return B0_impl(&p10, &m02, &m12, &scl2);
   }

   /* Delete me */
   bool is_zero(std::complex<double> a) noexcept
   {
      double prec = std::numeric_limits<double>::epsilon();
      return std::abs(a) <= prec;
   }

   std::complex<double> Collier::C0(
         std::complex<double> p10_in, std::complex<double> p21_in, std::complex<double> p20_in,
         std::complex<double> m02_in, std::complex<double> m12_in, std::complex<double> m22_in,
         double scl2_in) noexcept {

      /* Non-vanishing imaginary parts of momentum invariants are not yet
       * suppoted by the current version (1.2.3) of COLLIER. */
      const std::complex<double> p10 (p10_in.real(), 0.);
      const std::complex<double> p21 (p21_in.real(), 0.);
      const std::complex<double> p20 (p20_in.real(), 0.);
      const std::complex<double> m02 = m02_in;
      const std::complex<double> m12 = m12_in;
      const std::complex<double> m22 = m22_in;
      double scl2 = scl2_in;

      return C0_impl(&p10, &p21, &p20, &m02, &m12, &m22, &scl2);
   }
   std::complex<double> Collier::C00(
         std::complex<double> p10_in, std::complex<double> p21_in, std::complex<double> p20_in,
         std::complex<double> m02_in, std::complex<double> m12_in, std::complex<double> m22_in,
         double scl2_in) noexcept {
      /* Non-vanishing imaginary parts of momentum invariants are not yet
      * suppoted by COLLIER-1.2.3. */
      const std::complex<double> p10 (p10_in.real(), 0.);
      const std::complex<double> p21 (p21_in.real(), 0.);
      const std::complex<double> p20 (p20_in.real(), 0.);
      const std::complex<double> m02 = m02_in;
      const std::complex<double> m12 = m12_in;
      const std::complex<double> m22 = m22_in;
      double scl2 = scl2_in;

      return C00_impl(&p10, &p21, &p20, &m02, &m12, &m22, &scl2);
   }
//}