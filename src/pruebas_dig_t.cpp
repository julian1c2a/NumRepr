#include "utilities.hpp"
#include "nat_reg_digs_t.hpp"
#include <typeinfo>

//template<NumRepr::uint128_t B,NumRepr::uint128_t L>
//consteval inline
//NumRepr::uint128_t Base_pow_to_Size() noexcept {
//	if constexpr (L==0)
//		return static_cast<NumRepr::uint128_t>(1);
//	else if constexpr (L==1)
//		return static_cast<NumRepr::uint128_t>(B);
//	else if constexpr (L==2)
//		return static_cast<NumRepr::uint128_t>(B)*static_cast<NumRepr::uint128_t>(B);
//	else
//		return (static_cast<NumRepr::uint128_t>(B)*Base_pow_to_Size<B,L-1>());
//}

template<size_t B,size_t L>
constexpr inline
NumRepr::uint128_t
conversion_to_int(NumRepr::register_of_digits_t<B,L> & arg) noexcept {
	namespace NR = NumRepr;
	namespace us = utilities::special;
	return us::conversion_to_int<B,L,NR::register_of_digits_t<B,L>>(arg);
}

using trisums_t = std::tuple<std::int64_t,std::int64_t,std::int64_t>;

using result_test_binop_con_asignacion = std::vector<trisums_t>;

using retorno_de_test_t = std::tuple<	bool,
																			result_test_binop_con_asignacion,
																			result_test_binop_con_asignacion>;

template<NumRepr::ullint_t Base,NumRepr::ullint_t Longitud>
retorno_de_test_t test_suma_con_asignacion() {
	using rd_t = NumRepr::register_of_digits_t<Base,Longitud>;
	using d_t  = NumRepr::digit_t<Base>;
	namespace us = utilities::special;
	namespace NR = NumRepr;
	bool todo_correcto = true;

	constexpr NR::uint128_t B2L{us::Base_pow_to_Size<Base,Longitud>()};

	std::vector<trisums_t> correctos{};
	correctos.reserve(B2L*B2L);
	std::vector<trisums_t> errores{};
	errores.reserve(B2L*B2L);

	rd_t rd_x{};
	rd_x.fill(d_t{0});
	rd_t rd_y{};
	rd_y.fill(d_t{0});
	for(std::uint64_t ix{0} ; ix < B2L ; ++ix) {
		for(std::uint64_t iy{0} ; iy < B2L ; ++iy) {
			rd_t rd_z{rd_x};
			NR::m_sum(rd_z,rd_y);
			const std::uint64_t iz = conversion_to_int<Base,Longitud>(rd_z);
			const std::uint64_t iw = (ix+iy)%B2L;
			const bool bien {iz==iw};
			const trisums_t trio{ix,iy,iz};
			if (!bien) {
				rd_t rd_w{rd_x};
				NR::m_sum(rd_w,rd_y);
				errores.push_back(trio);
			} else {
				correctos.push_back(trio);
			}
			todo_correcto = todo_correcto && bien;
			m_incr(rd_y);
		}
		m_incr(rd_x);
	}
	return retorno_de_test_t{todo_correcto,correctos,errores};
}


int main() {
	/// digit_t<B>
	/// reg_digs_t<B,L>
	using namespace NumRepr;
//	constexpr ullint_t B{10u};
//	//constexpr ullint_t Bm1{B-1};
//	constexpr size_t L{5};
//	using rd_t = register_of_digits_t<B,L>;
	//using d_t = digit_t<B>;
	/// PRUEBAS SOBRE LA DIVISION
	/// FUNCION AUXILIAR aprox_units_divB
//	rd_t opndo{1,3,5,2,6};
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo >>= 1;
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo >>= 1;
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo >>= 1;
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo >>= 1;
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo >>= 1;
//	std::cout << opndo << std::endl;
//	std::cout << opndo.index_of_MSDig() << std::endl;
//	opndo = rd_t{6,6,7,9,5};
//	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
//	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
//	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
//	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
//	std::cout << "aprox to units of " << opndo << " is " << (opndo=aprox_units_divB(opndo)) << std::endl;
//	rd_t lopndo{9,9,8,2,5};
//	rd_t ropndo{0,0,5,8,7};
//	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,4>(lopndo) << std::endl;
//	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,3>(lopndo) << std::endl;
//	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,2>(lopndo) << std::endl;
//	std::cout << " aprox of " << lopndo  <<  " is " << aprox_units_divB_n<uchint_t,10,5,1>(lopndo) << std::endl;

	constexpr ullint_t B2{2u};
	constexpr size_t L2{10};
	{
		std::cout << std::boolalpha;
		auto resultado{test_suma_con_asignacion<B2,L2>()};
		auto todo_correcto{std::get<0>(resultado)};
		auto correctos{std::get<1>(resultado)};
		auto errores{std::get<2>(resultado)};
		std::cout << "TEST para la suma y asignacion sobre el tipo register_of_digits_t<"
							<< int(B2) << "," << int(L2) << ">" << std::endl;
		std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
		std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
		std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
	}
	constexpr ullint_t B1{10u};
	constexpr size_t L1{3};
	{
		std::cout << std::boolalpha;
		auto resultado{test_suma_con_asignacion<B1,L1>()};
		auto todo_correcto{std::get<0>(resultado)};
		auto correctos{std::get<1>(resultado)};
		auto errores{std::get<2>(resultado)};
		std::cout << "TEST para la suma y asignacion sobre el tipo register_of_digits_t<"
							<< int(B1) << "," << int(L1) << ">" << std::endl;
		std::cout << "El vector \"correctos\" tiene " << correctos.size() << " elementos " << std::endl;
		std::cout << "El vector \"errores  \" tiene " << errores.size() << " elementos " << std::endl;
		std::cout << "Todo ha ido bien : " << todo_correcto << std::endl;
	}

	return 0;
}

