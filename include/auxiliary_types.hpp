#ifndef AUXILIARY_TYPES_HPP_INCLUDED
#define AUXILIARY_TYPES_HPP_INCLUDED


namespace NumRepr {

/****************************/
//
//	SIGNO
//
/****************************/

enum class sign_funct_e : char { vzero = 0, vminus = -1, vplus = +1 };
enum class dig_format_e : unsigned char {
  BINnat = 0,
  BCDnat = 1,
  BCDexc3 = 2,
  BCDaitk = 3,
  johnson_n = 4,
  biquinario = 5
}; /// A INTRODUCIR
enum class num_type_e : unsigned char {
  natural = 0,
  entero = 1,
  racional = 2,
  real = 3
}; /// YA INTRODUCIDO, PERO NO EXPLICITAMENTE NI COMPLETAMENTE
enum class nat_num_format_e : bool {
  natural = false,
  exc_n = true
}; /// SOLO NATURAL
enum class int_num_format_e : unsigned char {
  int_CB = 0,
  int_CBm1 = 1,
  int_MS = 2,
  int_EXC_n = 3
}; /// EN C_B YA QUEDA EN MS
enum class rat_num_format_e : unsigned char {
  pair_num_den = 0,
  fxd_pt = 1,
  flt_pt = 2
};

enum class binop_e { add, sub, mult, div, rem, fediv, other };

} // namespace NumRepr

#endif // AUXILIARY_TYPES_HPP_INCLUDED
