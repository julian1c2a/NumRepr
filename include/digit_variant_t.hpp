#ifndef DIGIT_VARIANT_T_HPP_INCLUDED
#define DIGIT_VARIANT_T_HPP_INCLUDED

#include <algorithm>
#include <cassert>
#include <cctype>
#include <charconv>
#include <cinttypes>
#include <concepts>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <variant>

#include "dig_t.hpp"

namespace NumRepr {

using std::abs;
using std::integral;
using std::isspace;
using std::string;
using std::unsigned_integral;

//enum class radixformat { bin, dec };

constexpr static std::uint64_t size_of_variant=64ull;

struct digit_variant;

/// TC_variant es un variant que depende de un solo Template Class
template <template <std::uint64_t I> class TC, class>
struct TC_variant;

template <template <std::uint64_t I> class TC, std::uint64_t... Is>
struct TC_variant<TC, std::index_sequence<Is...>> {
  using type = std::variant<TC<Is+2>...>;
};

template <template <std::uint64_t I> class TC, class TSeq>
using TC_variant_t = typename TC_variant<TC, TSeq>::type;

using digit_variant_t = TC_variant_t<dig_t , std::make_index_sequence<size_of_variant>>;

/// TIPOS
/// DIGIT_VARIANT
/// REG_DIG_VARIANT
/// NAT_REG_VARIANT
/// INT_REG_VARIANT
/// NAT_VARIANT
/// INT_VARIANT

//struct digit_variant;
digit_variant make_digit_variant(std::uint64_t,std::int64_t);

using ldouble_t = long double;
using sllint_t = long long int;
using ullint_t = unsigned long long int;

struct digit_variant : public digit_variant_t
{
  using UINT_T = typename dig_t<255ull>::UINT_T;
  using SIG_UINT_T = typename dig_t<255ull>::SIG_UINT_T;
  using SIG_SINT_T = typename dig_t<255ull>::SIG_SINT_T;

  static constexpr size_t digits = std::numeric_limits<std::uint64_t>::digits;

  UINT_T get() const noexcept;

  UINT_T operator()() const noexcept;

  void set_0() noexcept;
  void set_1() noexcept;
  void set_Bm1() noexcept;
  void set_Bm2() noexcept;
  void set_dig(digit_variant) noexcept;
  void set_dig(UINT_T) noexcept;

  ////////////////////////////////////////////////////////////////////////////
  bool is_prime_base() const noexcept;
  ////////////////////////////////////////////////////////////////////////////
  digit_variant dig_max() noexcept;
  digit_variant dig_submax() noexcept;
  digit_variant dig_Bm1() noexcept;
  digit_variant dig_Bm2() noexcept;
  digit_variant dig_0() noexcept;
  digit_variant dig_1() noexcept;
  ////////////////////////////////////////////////////////////////////////////
  UINT_T ui_max() noexcept;
  UINT_T ui_submax() noexcept;
  UINT_T ui_Bm1() noexcept;
  UINT_T ui_Bm2() noexcept;
  UINT_T ui_0() noexcept;
  UINT_T ui_1() noexcept;
  ////////////////////////////////////////////////////////////////////////////
  SIG_UINT_T sui_B() noexcept;

  SIG_UINT_T sui_max() noexcept;

  SIG_UINT_T sui_Bm1() noexcept;

  SIG_UINT_T sui_submax() noexcept;

  SIG_UINT_T sui_Bm2() noexcept;

  SIG_UINT_T sui_0() noexcept;

  SIG_UINT_T sui_1() noexcept;

  ////////////////////////////////////////////////////////////////////////////
  SIG_SINT_T ssi_B() noexcept;

  SIG_SINT_T ssi_max() noexcept;

  SIG_SINT_T ssi_Bm1() noexcept;

  SIG_SINT_T ssi_submax() noexcept;

  SIG_SINT_T ssi_Bm2() noexcept;

  SIG_SINT_T ssi_0() noexcept;

  SIG_SINT_T ssi_1() noexcept;

  ////////////////////////////////////////////////////////////////////////////

  /************************************/
  /*								  */
  /*	CONSTRUIR DIGITO			  */
  /*								  */
  /************************************/

  ///< CONSTRUCTORES
  ///< CONSTRUCTOR POR DEFECTO
  consteval digit_variant() noexcept : digit_variant_t(dig_t<2ull>{}) {}

  /// CONSTRUCTOR ESPECÍFICO A PARTIR DE UN DIG_T
  template <std::uint64_t Base> requires (Base > 1ull)
  constexpr digit_variant(dig_t<Base> arg) noexcept : digit_variant_t{arg}
  {}

  /// CONSTRUCTOR ESPECÍFICO A PARTIR DE 2 ENTEROS
  digit_variant(std::uint64_t argBase,std::int64_t argValue)
  	noexcept : digit_variant{make_digit_variant(argBase,argValue)}
  {}

  /// CONSTRUCTOR COPIA POR REFERENCIA
  constexpr digit_variant(const digit_variant &) noexcept = default;
  /// CONSTRUCTOR POR MOVIMIENTO
  constexpr digit_variant(digit_variant &&) noexcept = default;

  /// PODEMOS PASAR ARGUMENTOS POR COPIA, REFERENCIA (PUNTEROS) Y MOVIMIENTO
  /// COPIA 		: COPIA EL ARGUMENTO LITERALMENTE PARA PASARLO: EL ORIGINAL
  /// INTACTO REFERENCIA: COPIA LA DIRECCION DEL ARGUMENTO
  ///             (SI ES CONST EL COMPILADOR NO TE DEJA COMPILAR SI LO CAMBIAS)
  /// MOVIMIENTO: SI EL ARGUMETO NO SE VA A UTILIZAR MAS SE LE PASA LA PROPIEDAD
  /// A LA FUNCION

  /************************************/
  /*								  */
  /*	OPERADORES DE ASIGNACION	  */
  /*								  */
  /************************************/

  /// SOBRECARGA DEL OPERATOR=() MEDIANTE REFERENCIA CTE DESDE UN INT_T
  template <type_traits::integral_c Int_t>
  const digit_variant& operator=(const Int_t & argint) noexcept {
  	auto fn =
  		[&argint]<std::uint64_t K>(dig_t<K>& leftArg) -> const digit_variant& {
  			leftArg = argint;
  			return (leftArg);
  		}
  	;
  	return std::visit(fn,*this);
  }

//  /// SOBRECARGA DEL OPERATOR=() MEDIANTE REFERENCIA CTE DESDE UN DIG_T
//  template <std::uint64_t Base>
//  const digit_variant& operator=(const dig_t<Base> &arg) noexcept {
//  	auto fn =
//		[]<std::uint64_t K, std::uint64_t L>(dig_t<K>& leftArg,const dig_t<L>& rightArg)
//			-> void
//		{
//			if constexpr ((K == L)&&(K==Base)) {
//				leftArg = rightArg;
//			}
//		}
//	;// END LAMBDA EXPRESSION DEFINITION
//  	std::visit(fn,*this,arg);
//  	return (*this);
//  }

  /// SOBRECARGA DEL OPERATOR=() MEDIANTE REFERENCIA CTE DESDE UN DIG_T
  digit_variant &operator=(const digit_variant &) noexcept = default;

  /// SOBRECARGA DEL OPERATOR=() MEDIANTE MOVIMIENTO DESDE UN DIG_T
  digit_variant &operator=(digit_variant &&) noexcept = default;
  /// a y b son digitos;
  /// a = std::move(b);
  /// a es identico a b; en b puede no queda nada;

  ///*************************************///
  ///< SENTIDO DE LA DIVISION DE DIGITOS >///
  ///*************************************///

  bool is_unit() const noexcept;

  bool is_0_divisor() const noexcept;

  digit_variant mult_inv() const noexcept;

  /**************************************/
  /*									*/
  /*	FUNCIONES PARA CONOCER EL CARRY	*/
  /*									*/
  /**************************************/

  static digit_variant sum_carry(digit_variant,digit_variant) noexcept;

  /************************************/
  /*								  */
  /*	OPERADORES & &= | |=    	  */
  /*  FUNCIONAN COMO MAX Y MIN		  */
  /*								  */
  /************************************/

  /// DEVOLVER EL MENOR: ANDBITWISE
  /// NO TIENE POSIBILIDAD DE ERROR
  digit_variant operator&(const digit_variant &arg) const noexcept;

  /// DEVOLVER EL MENOR HABIENDOLO ASIGNADO ANDBITWISE AND ASSIGN
  /// NO TIENE POSIBILIDAD DE ERROR
  const digit_variant &operator&=(digit_variant arg) noexcept;

  /// DEVOLVER EL MAYOR ORBITWISE
  /// NO TIENE POSIBILIDAD DE ERROR
  digit_variant operator|(const digit_variant &arg) const noexcept;

  /// DEVOLVER EL MAYOR HABIENDOLO ASIGNADO ORBITWISE AND ASSIGN
  /// NO TIENE POSIBILIDAD DE ERROR
  const digit_variant &operator|=(digit_variant) noexcept;

  /******************************************************/
  /*													*/
  /*	OPERADORES *^n *^=n                             */
  /*  FUNCIONAN COMO Power(*,n) y n = Power(*,n)		*/
  /*	DONDE n ES NATURAL                              */
  /*													*/
  /******************************************************/

  template <type_traits::unsigned_integral_c UIntType>
  constexpr const digit_variant& operator^=(UIntType exp) noexcept;

  template <type_traits::unsigned_integral_c UIntType>
  constexpr digit_variant operator^(UIntType exp) const noexcept;

  /****************************************/
  /*				               		  */
  /* OPERADORES COMPARACION				  */
  /*				                	  */
  /****************************************/

  bool operator==(digit_variant) const noexcept;

  bool operator!=(digit_variant) const noexcept;

  bool operator>=(digit_variant) const noexcept;

  bool operator>(digit_variant) const noexcept;

  bool operator<=(digit_variant) const noexcept;

  bool operator<(digit_variant) const noexcept;

  /// SI COMPARAMOS O HACEMOS UNA OPERACION CON UN INT_T SIEMPRE SERA
  /// DIG_T @ INT_T -> DIG_T Y NUNCA INT_T @ DIG_T -> ANY_TYPE
  /// METODO PROPIO DE C++20

  std::strong_ordering operator<=>(digit_variant) const noexcept;

  template <type_traits::integral_c Int_t>
  bool operator==(Int_t rhs) const noexcept;

  template<type_traits::integral_c Int_t>
  bool operator!=(Int_t rhs) const noexcept;

  template<type_traits::integral_c Int_t>
  bool operator<(Int_t rhs) const noexcept;

  template<type_traits::integral_c Int_t>
  bool operator<=(Int_t rhs) const noexcept;

  template<type_traits::integral_c Int_t>
  bool operator>(Int_t rhs) const noexcept;

  template<type_traits::integral_c Int_t>
  bool operator>=(Int_t rhs) const noexcept;

  /// METODO PROPIO DE C++20
  /// ESTABLECEMOS UN ORDEN PARCIAL SOBRE LOS ENTEROS SI a b EN Z
  /// ESTANDO EN ESTE AMBITO DE BASE B SI a mod B = b mod B
  template <type_traits::integral_c Int_t>
  std::weak_ordering operator<=>(Int_t rhs) const noexcept;

  /********************************************/
  /*				    					  */
  /*   ARITMETICOS CON ASIGNACION     		  */
  /*				    					  */
  /********************************************/

  const digit_variant& operator+=(digit_variant arg) noexcept;

  template <type_traits::integral_c Int_t>
  const digit_variant &operator+=(Int_t arg) noexcept;

  const digit_variant& operator-=(digit_variant arg) noexcept;

  template <type_traits::integral_c Int_t>
  const digit_variant &operator-=(Int_t arg) noexcept;

  const digit_variant& operator*=(digit_variant arg) noexcept;

  template <type_traits::integral_c Int_t>
  const digit_variant& operator*=(Int_t arg) noexcept;

  const digit_variant& operator/=(digit_variant arg) noexcept;

  template <type_traits::integral_c Int_t>
  const digit_variant& operator/=(Int_t arg) noexcept;

  const digit_variant& operator%=(digit_variant arg) noexcept;

  template <type_traits::integral_c Int_t>
  const digit_variant& operator%=(Int_t arg) noexcept;

  /// Tengo serias dudas que la division y el resto euclideo tengan cabida
  /// entre los operadores aritmeticos de un tipo digit_variant
  /// DUDA SATISFECHA: TIENEN CABIDA PORQUE EL INVERSO MULTIPLICATIVO ETC.
  /// SOLO NOS SIRVE SI ESTUVIERAMOS CONSTRUYENDO NUMEROS DE UN ANILLO FINITO

  /********************************/
  /*			     			  */
  /* 		  PRE Y POST 		  */
  /*			CIRCULARES		  */
  /*							  */
  /********************************/

  const digit_variant& operator++() noexcept;

  digit_variant operator++(int) noexcept;

  const digit_variant& operator--() noexcept;

  digit_variant operator--(int) noexcept;

  /****************************************/
  /*									  */
  /*    OPERADORES ARITMETICOS   		  */
  /*									  */
  /****************************************/

  digit_variant operator+(digit_variant) const noexcept;

  digit_variant operator-(digit_variant) const noexcept;

  digit_variant operator*(digit_variant) const noexcept;

  digit_variant operator/(digit_variant) const noexcept;

  digit_variant operator%(digit_variant) const noexcept;

  template <type_traits::integral_c Int_type>
  digit_variant operator+(Int_type) const noexcept;

  template <type_traits::integral_c Int_type>
  digit_variant operator-(Int_type) const noexcept;

  template <type_traits::integral_c Int_type>
  digit_variant operator*(Int_type) const noexcept;

  template <type_traits::integral_c Int_type>
  digit_variant operator/(Int_type) const noexcept;

  template <type_traits::integral_c Int_type>
  digit_variant operator%(Int_type) const noexcept;

  /****************************************/
  /*									  */
  /*	     COMPLEMENTO BASE 			  */
  /*	      Y BASE MENOS 1			  */
  /*									  */
  /****************************************/

  /// EN BASE B, B-1-m_d ES EL COMPL_Bm1(m_d)
  digit_variant operator~() const noexcept;

  /// EN BASE B, B-m_d ES EL COMPL_B(m_d)
  digit_variant operator-() const noexcept;

  /// "C_Bm1" es identico a "operator!()"
  digit_variant C_Bm1() const noexcept;

  /// "C_B" es identico a "operator-()"
  digit_variant C_B() const noexcept;

  /****************************************************/
  /*				    							  */
  /*    MODIFICADORES COMPLEMENTO	    			  */
  /*				    							  */
  /****************************************************/

  const digit_variant &mC_Bm1() noexcept;

  const digit_variant &mC_B() noexcept;

  /**********************************/
  /*                            	*/
  /*   	NULO Y MAXIMO         	  	*/
  /*                            	*/
  /**********************************/

  bool is_0() const noexcept;

  bool is_1() const noexcept;

  bool is_0or1() const noexcept;

  bool is_not_1() const noexcept;

  bool is_not_0() const noexcept;

  bool is_not_0or1() const noexcept;

  bool is_Bm1() const noexcept;

  bool is_not_Bm1() const noexcept;

  bool is_Bm1orBm2() const noexcept;

  bool is_not_Bm1orBm2() const noexcept;

  bool is_Bm2() const noexcept;

  bool is_not_Bm2() const noexcept;

  bool is_not_maxormin() const noexcept;

  bool is_maxormin() const noexcept;

  bool is_far_maxormin() const noexcept;

  bool is_near_maxormin() const noexcept;

  /********************************/
  /*							  */
  /* 	     VARIOS CASTS		  */
  /*							  */
  /********************************/
  std::uint64_t radix() const noexcept;

  std::string to_string() const noexcept;
}; /// END OF CLASS DIGIT_VARIANT

/************************************/
/*                                  */
/*         ISTREAM Y OSTREAM        */
/*                                  */
/************************************/

std::istream &operator>>(std::istream &,digit_variant&);

std::ostream &operator<<(std::ostream &,const digit_variant&);

} // END OF NAMESPACE NUMREPR IN THIS TRANSLATION UNIT

#endif // DIGIT_VARIANT_T_HPP_INCLUDED
