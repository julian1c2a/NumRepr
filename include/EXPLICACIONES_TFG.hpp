#include <string>

using std::string = std::basic_string<char>;

template<std::uint64_t B>
using dig_string_t = std::basic_string<dig_t<B>>;

// basic_num_t -> dig_string_t
constexpr bool mismo_tipo = is_same<dig_string_t<B>,basic_string<dig_t<B>>;
// mismo_tipo == true

                            basic_types.hpp utilities.hpp
                            auxiliar_types.hpp auxiliar_functions.hpp
                            
                        dig_t.hpp
                        digit_variant_t.hpp
                        digit_variant_t.cpp
                        
                        reg_digs_t.hpp tipo intermedio no-número 
                                       registro fijo de dígitos
                                       
                    nat_reg_digs_t.hpp       int_reg_digs_t.hpp
                    Números sin signo de     Números con signo de 
                    longitud fija            longitud fija
                    
                nat_reg_digs_variant_t.hpp      int_reg_digs_variant_t.hpp
                nat_reg_digs_variant_t.cpp      int_reg_digs_variant_t.cpp
                make_nat_reg_digs_variant_t.cpp make_int_reg_digs_variant_t.cpp
                
                nat_rat_fixed_reg_t.hpp     int_rat_fixed_reg_t.hpp
                tipo de número sin signo    tipo de número con signo
                con número de dígitos fijos con número de dígitos fijos
                en la parte entera (LE)     en la parte entera (LE)
                y número                    y número
                de dígitos fijo en la parte de dígitos fijo en la parte
                fraccionaria (LF).          fraccionaria (LF).
                
                
            nat_rat_fixed_reg_variant_t.hpp         int_rat_fixed_reg_variant_t.hpp
            nat_rat_fixed_reg_variant_t.cpp         int_rat_fixed_reg_variant_t.cpp
            make_nat_rat_fixed_reg_variant_t.cpp    make_int_rat_fixed_reg_variant_t.cpp
            
                                dig_string_t.hpp
                tipo de cadena de dígitos en una base determinada
                No es una plantilla numérica.
                
            nat_num_t.hpp                       int_num_t.hpp
            Número sin signo de longitud        Número con signo de longitud
            dinámica y base cualquiera a        dinámica y base cualquiera a
            especificar. Deriva de              especificar. Deriva de
            template<uint64_t B> dig_string_t   template<uint64_t B> dig_string_t

            nat_num_variant_t.hpp               int_num_variant_t.hpp
            nat_num_variant_t.cpp               int_num_variant_t.cpp
            make_nat_num_variant_t.cpp          make_int_num_variant_t.cpp
            
                            memory_handler.hpp
                            memory_hnadler.cpp
                            
                            varlist_definitions.hpp
                            varlist_definitions.cpp
                            
            
        NIVELES DE LA LIBRERÍA

        [0] BASIC_TYPES 
            UTILITIES 
            UTIL_FUNCTS 
            AUXILIAR_TYPES 
            AUXILIAR_FUNCTIONS
            Ficheros cabecera para poder hacer la metaprogramación 
            necesaria y utilidades comunes
        
        [1] DIG_T
        
        [2] REG_DIGS_T
            DIG_STRING_T 
            No numéricos [NO EN GUI]
        
        [3] NAT_REG_DIGS_T      INT_REG_DIGS_T
            NAT_RAT_FIXED_REG_T INT_RAT_FIXED_REG_T
            NAT_NUM_T           INT_NUM_T
        
        [4] DIGIT_VARIANT_T
            NAT_REG_VARIANT_T
            INT_REG_VARIANT_T
            NAT_RAT_FIXED_REG_VARIANT_T 
            INT_RAT_FIXED_REG_VARIANT_T
            NAT_NUM_VARIANT_T           
            INT_NUM_VARIANT_T
            
        [5] MEMORY_HANDLER
            VARLIST_DEFINITIONS
            
        
        
        template<std::uint64_t B>
        class dig_t;
        
        dig_t<2>
        dig_t<3>
        ........
        dig_t<64>
        dig_t<65>
        .........
        dig_t<65535>
        dig_t<65536>
        ............
        dig_t<1024*1024-1>
        dig_t<1024*1024>
        dig_t<1024*1024+1>
        ..................
        dig_t<999999999-1>
        dig_t<999999999>
        dig_t<999999999+1>
        ..................
        
        class digit_variant_t : 
            public std::variant<dig_t<2>,dig_t<3>,dig_t<4>,...,dig_t<66>>;
        digit_variant_t A;
        A = dig_t<48>(25);
        A = dig_t<33>(17);
        
        dig_t operator+(dig_t) const {
            // funcionamiento
            return resultado;
        }
        
        digit_variant_t operator+ (digit_variant_t) const {
            return std::visit(dig_t operator+(dig_t) const, arg_1, arg_2);
        }
        
        