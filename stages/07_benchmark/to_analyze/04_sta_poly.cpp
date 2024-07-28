#include <cstdint>
#include <concepts>
#include <type_traits>

template <std::uint32_t address>
class CRegister {
public:
    static inline void set (std::uint32_t val) {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = val;
    }

    static inline std::uint32_t get () {
        return *(reinterpret_cast<volatile std::uint32_t *>(address));
    }

    static inline void set (std::uint32_t value, std::uint32_t bitmask) {
        std::uint32_t tmp = get();
        tmp &= ~bitmask;
        tmp |= value;
        set(tmp);
    }

    static inline void set_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = *(reinterpret_cast<volatile std::uint32_t *>(address)) | bitmask;
    }

    static inline void clear_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = *(reinterpret_cast<volatile std::uint32_t *>(address)) & ~bitmask;
    }

    static inline bool is_set (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask) == bitmask;
    }

    static inline bool is_cleared (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask) == 0;
    }

    static inline std::uint32_t get_bits (std::uint32_t bitmask) {
        return *(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask;
    }
};
#define CONST_0 0x0UL
#define CONST_1 0x1UL
#define CONST_2 0x2UL
#define CONST_3 0x3UL
#define CONST_4 0x4UL
#define CONST_5 0x5UL
#define CONST_6 0x6UL
#define CONST_7 0x7UL
#define CONST_8 0x8UL
#define CONST_9 0x9UL
#define CONST_10 0xaUL
#define CONST_11 0xbUL
#define CONST_12 0xcUL
#define CONST_13 0xdUL
#define CONST_14 0xeUL
#define CONST_15 0xfUL
#define CONST_16 0x10UL
#define CONST_17 0x11UL
#define CONST_18 0x12UL
#define CONST_19 0x13UL
#define CONST_20 0x14UL
#define CONST_21 0x15UL
#define CONST_22 0x16UL
#define CONST_23 0x17UL
#define CONST_24 0x18UL
#define CONST_25 0x19UL
#define CONST_26 0x1aUL
#define CONST_27 0x1bUL
#define CONST_28 0x1cUL
#define CONST_29 0x1dUL
#define CONST_30 0x1eUL
#define CONST_31 0x1fUL
#define CONST_32 0x20UL
#define CONST_33 0x21UL
#define CONST_34 0x22UL
#define CONST_35 0x23UL
#define CONST_36 0x24UL
#define CONST_37 0x25UL
#define CONST_38 0x26UL
#define CONST_39 0x27UL
#define CONST_40 0x28UL
#define CONST_41 0x29UL
#define CONST_42 0x2aUL
#define CONST_43 0x2bUL
#define CONST_44 0x2cUL
#define CONST_45 0x2dUL
#define CONST_46 0x2eUL
#define CONST_47 0x2fUL
#define CONST_48 0x30UL
#define CONST_49 0x31UL
#define CONST_50 0x32UL
#define CONST_51 0x33UL
#define CONST_52 0x34UL
#define CONST_53 0x35UL
#define CONST_54 0x36UL
#define CONST_55 0x37UL
#define CONST_56 0x38UL
#define CONST_57 0x39UL
#define CONST_58 0x3aUL
#define CONST_59 0x3bUL
#define CONST_60 0x3cUL
#define CONST_61 0x3dUL
#define CONST_62 0x3eUL
#define CONST_63 0x3fUL
#define CONST_64 0x40UL
#define CONST_65 0x41UL
#define CONST_66 0x42UL
#define CONST_67 0x43UL
#define CONST_68 0x44UL
#define CONST_69 0x45UL
#define CONST_70 0x46UL
#define CONST_71 0x47UL
#define CONST_72 0x48UL
#define CONST_73 0x49UL
#define CONST_74 0x4aUL
#define CONST_75 0x4bUL
#define CONST_76 0x4cUL
#define CONST_77 0x4dUL
#define CONST_78 0x4eUL
#define CONST_79 0x4fUL
#define CONST_80 0x50UL
#define CONST_81 0x51UL
#define CONST_82 0x52UL
#define CONST_83 0x53UL
#define CONST_84 0x54UL
#define CONST_85 0x55UL
#define CONST_86 0x56UL
#define CONST_87 0x57UL
#define CONST_88 0x58UL
#define CONST_89 0x59UL
#define CONST_90 0x5aUL
#define CONST_91 0x5bUL
#define CONST_92 0x5cUL
#define CONST_93 0x5dUL
#define CONST_94 0x5eUL
#define CONST_95 0x5fUL
#define CONST_96 0x60UL
#define CONST_97 0x61UL
#define CONST_98 0x62UL
#define CONST_99 0x63UL
typedef enum {
    ENUM_0_VAL_0 = 0x0UL,
    ENUM_0_VAL_1 = 0x1UL,
    ENUM_0_VAL_2 = 0x2UL,
    ENUM_0_VAL_3 = 0x3UL,
    ENUM_0_VAL_4 = 0x4UL,
    ENUM_0_VAL_5 = 0x5UL,
    ENUM_0_VAL_6 = 0x6UL,
    ENUM_0_VAL_7 = 0x7UL,
    ENUM_0_VAL_8 = 0x8UL,
    ENUM_0_VAL_9 = 0x9UL
} ENUM_0;
typedef enum {
    ENUM_1_VAL_0 = 0x0UL,
    ENUM_1_VAL_1 = 0x1UL,
    ENUM_1_VAL_2 = 0x2UL,
    ENUM_1_VAL_3 = 0x3UL,
    ENUM_1_VAL_4 = 0x4UL,
    ENUM_1_VAL_5 = 0x5UL,
    ENUM_1_VAL_6 = 0x6UL,
    ENUM_1_VAL_7 = 0x7UL,
    ENUM_1_VAL_8 = 0x8UL,
    ENUM_1_VAL_9 = 0x9UL
} ENUM_1;
typedef enum {
    ENUM_2_VAL_0 = 0x0UL,
    ENUM_2_VAL_1 = 0x1UL,
    ENUM_2_VAL_2 = 0x2UL,
    ENUM_2_VAL_3 = 0x3UL,
    ENUM_2_VAL_4 = 0x4UL,
    ENUM_2_VAL_5 = 0x5UL,
    ENUM_2_VAL_6 = 0x6UL,
    ENUM_2_VAL_7 = 0x7UL,
    ENUM_2_VAL_8 = 0x8UL,
    ENUM_2_VAL_9 = 0x9UL
} ENUM_2;
typedef enum {
    ENUM_3_VAL_0 = 0x0UL,
    ENUM_3_VAL_1 = 0x1UL,
    ENUM_3_VAL_2 = 0x2UL,
    ENUM_3_VAL_3 = 0x3UL,
    ENUM_3_VAL_4 = 0x4UL,
    ENUM_3_VAL_5 = 0x5UL,
    ENUM_3_VAL_6 = 0x6UL,
    ENUM_3_VAL_7 = 0x7UL,
    ENUM_3_VAL_8 = 0x8UL,
    ENUM_3_VAL_9 = 0x9UL
} ENUM_3;
typedef enum {
    ENUM_4_VAL_0 = 0x0UL,
    ENUM_4_VAL_1 = 0x1UL,
    ENUM_4_VAL_2 = 0x2UL,
    ENUM_4_VAL_3 = 0x3UL,
    ENUM_4_VAL_4 = 0x4UL,
    ENUM_4_VAL_5 = 0x5UL,
    ENUM_4_VAL_6 = 0x6UL,
    ENUM_4_VAL_7 = 0x7UL,
    ENUM_4_VAL_8 = 0x8UL,
    ENUM_4_VAL_9 = 0x9UL
} ENUM_4;
typedef enum {
    ENUM_5_VAL_0 = 0x0UL,
    ENUM_5_VAL_1 = 0x1UL,
    ENUM_5_VAL_2 = 0x2UL,
    ENUM_5_VAL_3 = 0x3UL,
    ENUM_5_VAL_4 = 0x4UL,
    ENUM_5_VAL_5 = 0x5UL,
    ENUM_5_VAL_6 = 0x6UL,
    ENUM_5_VAL_7 = 0x7UL,
    ENUM_5_VAL_8 = 0x8UL,
    ENUM_5_VAL_9 = 0x9UL
} ENUM_5;
typedef enum {
    ENUM_6_VAL_0 = 0x0UL,
    ENUM_6_VAL_1 = 0x1UL,
    ENUM_6_VAL_2 = 0x2UL,
    ENUM_6_VAL_3 = 0x3UL,
    ENUM_6_VAL_4 = 0x4UL,
    ENUM_6_VAL_5 = 0x5UL,
    ENUM_6_VAL_6 = 0x6UL,
    ENUM_6_VAL_7 = 0x7UL,
    ENUM_6_VAL_8 = 0x8UL,
    ENUM_6_VAL_9 = 0x9UL
} ENUM_6;
typedef enum {
    ENUM_7_VAL_0 = 0x0UL,
    ENUM_7_VAL_1 = 0x1UL,
    ENUM_7_VAL_2 = 0x2UL,
    ENUM_7_VAL_3 = 0x3UL,
    ENUM_7_VAL_4 = 0x4UL,
    ENUM_7_VAL_5 = 0x5UL,
    ENUM_7_VAL_6 = 0x6UL,
    ENUM_7_VAL_7 = 0x7UL,
    ENUM_7_VAL_8 = 0x8UL,
    ENUM_7_VAL_9 = 0x9UL
} ENUM_7;
typedef enum {
    ENUM_8_VAL_0 = 0x0UL,
    ENUM_8_VAL_1 = 0x1UL,
    ENUM_8_VAL_2 = 0x2UL,
    ENUM_8_VAL_3 = 0x3UL,
    ENUM_8_VAL_4 = 0x4UL,
    ENUM_8_VAL_5 = 0x5UL,
    ENUM_8_VAL_6 = 0x6UL,
    ENUM_8_VAL_7 = 0x7UL,
    ENUM_8_VAL_8 = 0x8UL,
    ENUM_8_VAL_9 = 0x9UL
} ENUM_8;
typedef enum {
    ENUM_9_VAL_0 = 0x0UL,
    ENUM_9_VAL_1 = 0x1UL,
    ENUM_9_VAL_2 = 0x2UL,
    ENUM_9_VAL_3 = 0x3UL,
    ENUM_9_VAL_4 = 0x4UL,
    ENUM_9_VAL_5 = 0x5UL,
    ENUM_9_VAL_6 = 0x6UL,
    ENUM_9_VAL_7 = 0x7UL,
    ENUM_9_VAL_8 = 0x8UL,
    ENUM_9_VAL_9 = 0x9UL
} ENUM_9;
typedef enum {
    ENUM_10_VAL_0 = 0x0UL,
    ENUM_10_VAL_1 = 0x1UL,
    ENUM_10_VAL_2 = 0x2UL,
    ENUM_10_VAL_3 = 0x3UL,
    ENUM_10_VAL_4 = 0x4UL,
    ENUM_10_VAL_5 = 0x5UL,
    ENUM_10_VAL_6 = 0x6UL,
    ENUM_10_VAL_7 = 0x7UL,
    ENUM_10_VAL_8 = 0x8UL,
    ENUM_10_VAL_9 = 0x9UL
} ENUM_10;
typedef enum {
    ENUM_11_VAL_0 = 0x0UL,
    ENUM_11_VAL_1 = 0x1UL,
    ENUM_11_VAL_2 = 0x2UL,
    ENUM_11_VAL_3 = 0x3UL,
    ENUM_11_VAL_4 = 0x4UL,
    ENUM_11_VAL_5 = 0x5UL,
    ENUM_11_VAL_6 = 0x6UL,
    ENUM_11_VAL_7 = 0x7UL,
    ENUM_11_VAL_8 = 0x8UL,
    ENUM_11_VAL_9 = 0x9UL
} ENUM_11;
typedef enum {
    ENUM_12_VAL_0 = 0x0UL,
    ENUM_12_VAL_1 = 0x1UL,
    ENUM_12_VAL_2 = 0x2UL,
    ENUM_12_VAL_3 = 0x3UL,
    ENUM_12_VAL_4 = 0x4UL,
    ENUM_12_VAL_5 = 0x5UL,
    ENUM_12_VAL_6 = 0x6UL,
    ENUM_12_VAL_7 = 0x7UL,
    ENUM_12_VAL_8 = 0x8UL,
    ENUM_12_VAL_9 = 0x9UL
} ENUM_12;
typedef enum {
    ENUM_13_VAL_0 = 0x0UL,
    ENUM_13_VAL_1 = 0x1UL,
    ENUM_13_VAL_2 = 0x2UL,
    ENUM_13_VAL_3 = 0x3UL,
    ENUM_13_VAL_4 = 0x4UL,
    ENUM_13_VAL_5 = 0x5UL,
    ENUM_13_VAL_6 = 0x6UL,
    ENUM_13_VAL_7 = 0x7UL,
    ENUM_13_VAL_8 = 0x8UL,
    ENUM_13_VAL_9 = 0x9UL
} ENUM_13;
typedef enum {
    ENUM_14_VAL_0 = 0x0UL,
    ENUM_14_VAL_1 = 0x1UL,
    ENUM_14_VAL_2 = 0x2UL,
    ENUM_14_VAL_3 = 0x3UL,
    ENUM_14_VAL_4 = 0x4UL,
    ENUM_14_VAL_5 = 0x5UL,
    ENUM_14_VAL_6 = 0x6UL,
    ENUM_14_VAL_7 = 0x7UL,
    ENUM_14_VAL_8 = 0x8UL,
    ENUM_14_VAL_9 = 0x9UL
} ENUM_14;
typedef enum {
    ENUM_15_VAL_0 = 0x0UL,
    ENUM_15_VAL_1 = 0x1UL,
    ENUM_15_VAL_2 = 0x2UL,
    ENUM_15_VAL_3 = 0x3UL,
    ENUM_15_VAL_4 = 0x4UL,
    ENUM_15_VAL_5 = 0x5UL,
    ENUM_15_VAL_6 = 0x6UL,
    ENUM_15_VAL_7 = 0x7UL,
    ENUM_15_VAL_8 = 0x8UL,
    ENUM_15_VAL_9 = 0x9UL
} ENUM_15;
typedef enum {
    ENUM_16_VAL_0 = 0x0UL,
    ENUM_16_VAL_1 = 0x1UL,
    ENUM_16_VAL_2 = 0x2UL,
    ENUM_16_VAL_3 = 0x3UL,
    ENUM_16_VAL_4 = 0x4UL,
    ENUM_16_VAL_5 = 0x5UL,
    ENUM_16_VAL_6 = 0x6UL,
    ENUM_16_VAL_7 = 0x7UL,
    ENUM_16_VAL_8 = 0x8UL,
    ENUM_16_VAL_9 = 0x9UL
} ENUM_16;
typedef enum {
    ENUM_17_VAL_0 = 0x0UL,
    ENUM_17_VAL_1 = 0x1UL,
    ENUM_17_VAL_2 = 0x2UL,
    ENUM_17_VAL_3 = 0x3UL,
    ENUM_17_VAL_4 = 0x4UL,
    ENUM_17_VAL_5 = 0x5UL,
    ENUM_17_VAL_6 = 0x6UL,
    ENUM_17_VAL_7 = 0x7UL,
    ENUM_17_VAL_8 = 0x8UL,
    ENUM_17_VAL_9 = 0x9UL
} ENUM_17;
typedef enum {
    ENUM_18_VAL_0 = 0x0UL,
    ENUM_18_VAL_1 = 0x1UL,
    ENUM_18_VAL_2 = 0x2UL,
    ENUM_18_VAL_3 = 0x3UL,
    ENUM_18_VAL_4 = 0x4UL,
    ENUM_18_VAL_5 = 0x5UL,
    ENUM_18_VAL_6 = 0x6UL,
    ENUM_18_VAL_7 = 0x7UL,
    ENUM_18_VAL_8 = 0x8UL,
    ENUM_18_VAL_9 = 0x9UL
} ENUM_18;
typedef enum {
    ENUM_19_VAL_0 = 0x0UL,
    ENUM_19_VAL_1 = 0x1UL,
    ENUM_19_VAL_2 = 0x2UL,
    ENUM_19_VAL_3 = 0x3UL,
    ENUM_19_VAL_4 = 0x4UL,
    ENUM_19_VAL_5 = 0x5UL,
    ENUM_19_VAL_6 = 0x6UL,
    ENUM_19_VAL_7 = 0x7UL,
    ENUM_19_VAL_8 = 0x8UL,
    ENUM_19_VAL_9 = 0x9UL
} ENUM_19;
typedef enum {
    ENUM_20_VAL_0 = 0x0UL,
    ENUM_20_VAL_1 = 0x1UL,
    ENUM_20_VAL_2 = 0x2UL,
    ENUM_20_VAL_3 = 0x3UL,
    ENUM_20_VAL_4 = 0x4UL,
    ENUM_20_VAL_5 = 0x5UL,
    ENUM_20_VAL_6 = 0x6UL,
    ENUM_20_VAL_7 = 0x7UL,
    ENUM_20_VAL_8 = 0x8UL,
    ENUM_20_VAL_9 = 0x9UL
} ENUM_20;
typedef enum {
    ENUM_21_VAL_0 = 0x0UL,
    ENUM_21_VAL_1 = 0x1UL,
    ENUM_21_VAL_2 = 0x2UL,
    ENUM_21_VAL_3 = 0x3UL,
    ENUM_21_VAL_4 = 0x4UL,
    ENUM_21_VAL_5 = 0x5UL,
    ENUM_21_VAL_6 = 0x6UL,
    ENUM_21_VAL_7 = 0x7UL,
    ENUM_21_VAL_8 = 0x8UL,
    ENUM_21_VAL_9 = 0x9UL
} ENUM_21;
typedef enum {
    ENUM_22_VAL_0 = 0x0UL,
    ENUM_22_VAL_1 = 0x1UL,
    ENUM_22_VAL_2 = 0x2UL,
    ENUM_22_VAL_3 = 0x3UL,
    ENUM_22_VAL_4 = 0x4UL,
    ENUM_22_VAL_5 = 0x5UL,
    ENUM_22_VAL_6 = 0x6UL,
    ENUM_22_VAL_7 = 0x7UL,
    ENUM_22_VAL_8 = 0x8UL,
    ENUM_22_VAL_9 = 0x9UL
} ENUM_22;
typedef enum {
    ENUM_23_VAL_0 = 0x0UL,
    ENUM_23_VAL_1 = 0x1UL,
    ENUM_23_VAL_2 = 0x2UL,
    ENUM_23_VAL_3 = 0x3UL,
    ENUM_23_VAL_4 = 0x4UL,
    ENUM_23_VAL_5 = 0x5UL,
    ENUM_23_VAL_6 = 0x6UL,
    ENUM_23_VAL_7 = 0x7UL,
    ENUM_23_VAL_8 = 0x8UL,
    ENUM_23_VAL_9 = 0x9UL
} ENUM_23;
typedef enum {
    ENUM_24_VAL_0 = 0x0UL,
    ENUM_24_VAL_1 = 0x1UL,
    ENUM_24_VAL_2 = 0x2UL,
    ENUM_24_VAL_3 = 0x3UL,
    ENUM_24_VAL_4 = 0x4UL,
    ENUM_24_VAL_5 = 0x5UL,
    ENUM_24_VAL_6 = 0x6UL,
    ENUM_24_VAL_7 = 0x7UL,
    ENUM_24_VAL_8 = 0x8UL,
    ENUM_24_VAL_9 = 0x9UL
} ENUM_24;
typedef enum {
    ENUM_25_VAL_0 = 0x0UL,
    ENUM_25_VAL_1 = 0x1UL,
    ENUM_25_VAL_2 = 0x2UL,
    ENUM_25_VAL_3 = 0x3UL,
    ENUM_25_VAL_4 = 0x4UL,
    ENUM_25_VAL_5 = 0x5UL,
    ENUM_25_VAL_6 = 0x6UL,
    ENUM_25_VAL_7 = 0x7UL,
    ENUM_25_VAL_8 = 0x8UL,
    ENUM_25_VAL_9 = 0x9UL
} ENUM_25;
typedef enum {
    ENUM_26_VAL_0 = 0x0UL,
    ENUM_26_VAL_1 = 0x1UL,
    ENUM_26_VAL_2 = 0x2UL,
    ENUM_26_VAL_3 = 0x3UL,
    ENUM_26_VAL_4 = 0x4UL,
    ENUM_26_VAL_5 = 0x5UL,
    ENUM_26_VAL_6 = 0x6UL,
    ENUM_26_VAL_7 = 0x7UL,
    ENUM_26_VAL_8 = 0x8UL,
    ENUM_26_VAL_9 = 0x9UL
} ENUM_26;
typedef enum {
    ENUM_27_VAL_0 = 0x0UL,
    ENUM_27_VAL_1 = 0x1UL,
    ENUM_27_VAL_2 = 0x2UL,
    ENUM_27_VAL_3 = 0x3UL,
    ENUM_27_VAL_4 = 0x4UL,
    ENUM_27_VAL_5 = 0x5UL,
    ENUM_27_VAL_6 = 0x6UL,
    ENUM_27_VAL_7 = 0x7UL,
    ENUM_27_VAL_8 = 0x8UL,
    ENUM_27_VAL_9 = 0x9UL
} ENUM_27;
typedef enum {
    ENUM_28_VAL_0 = 0x0UL,
    ENUM_28_VAL_1 = 0x1UL,
    ENUM_28_VAL_2 = 0x2UL,
    ENUM_28_VAL_3 = 0x3UL,
    ENUM_28_VAL_4 = 0x4UL,
    ENUM_28_VAL_5 = 0x5UL,
    ENUM_28_VAL_6 = 0x6UL,
    ENUM_28_VAL_7 = 0x7UL,
    ENUM_28_VAL_8 = 0x8UL,
    ENUM_28_VAL_9 = 0x9UL
} ENUM_28;
typedef enum {
    ENUM_29_VAL_0 = 0x0UL,
    ENUM_29_VAL_1 = 0x1UL,
    ENUM_29_VAL_2 = 0x2UL,
    ENUM_29_VAL_3 = 0x3UL,
    ENUM_29_VAL_4 = 0x4UL,
    ENUM_29_VAL_5 = 0x5UL,
    ENUM_29_VAL_6 = 0x6UL,
    ENUM_29_VAL_7 = 0x7UL,
    ENUM_29_VAL_8 = 0x8UL,
    ENUM_29_VAL_9 = 0x9UL
} ENUM_29;
#define IS_ENUM_0(X) (((X) == ENUM_0_VAL_0) || ((X) == ENUM_0_VAL_1) || ((X) == ENUM_0_VAL_2) || ((X) == ENUM_0_VAL_3) || ((X) == ENUM_0_VAL_4) || ((X) == ENUM_0_VAL_5) || ((X) == ENUM_0_VAL_6) || ((X) == ENUM_0_VAL_7) || ((X) == ENUM_0_VAL_8) || ((X) == ENUM_0_VAL_9))
#define IS_ENUM_1(X) (((X) == ENUM_1_VAL_0) || ((X) == ENUM_1_VAL_1) || ((X) == ENUM_1_VAL_2) || ((X) == ENUM_1_VAL_3) || ((X) == ENUM_1_VAL_4) || ((X) == ENUM_1_VAL_5) || ((X) == ENUM_1_VAL_6) || ((X) == ENUM_1_VAL_7) || ((X) == ENUM_1_VAL_8) || ((X) == ENUM_1_VAL_9))
#define IS_ENUM_2(X) (((X) == ENUM_2_VAL_0) || ((X) == ENUM_2_VAL_1) || ((X) == ENUM_2_VAL_2) || ((X) == ENUM_2_VAL_3) || ((X) == ENUM_2_VAL_4) || ((X) == ENUM_2_VAL_5) || ((X) == ENUM_2_VAL_6) || ((X) == ENUM_2_VAL_7) || ((X) == ENUM_2_VAL_8) || ((X) == ENUM_2_VAL_9))
#define IS_ENUM_3(X) (((X) == ENUM_3_VAL_0) || ((X) == ENUM_3_VAL_1) || ((X) == ENUM_3_VAL_2) || ((X) == ENUM_3_VAL_3) || ((X) == ENUM_3_VAL_4) || ((X) == ENUM_3_VAL_5) || ((X) == ENUM_3_VAL_6) || ((X) == ENUM_3_VAL_7) || ((X) == ENUM_3_VAL_8) || ((X) == ENUM_3_VAL_9))
#define IS_ENUM_4(X) (((X) == ENUM_4_VAL_0) || ((X) == ENUM_4_VAL_1) || ((X) == ENUM_4_VAL_2) || ((X) == ENUM_4_VAL_3) || ((X) == ENUM_4_VAL_4) || ((X) == ENUM_4_VAL_5) || ((X) == ENUM_4_VAL_6) || ((X) == ENUM_4_VAL_7) || ((X) == ENUM_4_VAL_8) || ((X) == ENUM_4_VAL_9))
#define IS_ENUM_5(X) (((X) == ENUM_5_VAL_0) || ((X) == ENUM_5_VAL_1) || ((X) == ENUM_5_VAL_2) || ((X) == ENUM_5_VAL_3) || ((X) == ENUM_5_VAL_4) || ((X) == ENUM_5_VAL_5) || ((X) == ENUM_5_VAL_6) || ((X) == ENUM_5_VAL_7) || ((X) == ENUM_5_VAL_8) || ((X) == ENUM_5_VAL_9))
#define IS_ENUM_6(X) (((X) == ENUM_6_VAL_0) || ((X) == ENUM_6_VAL_1) || ((X) == ENUM_6_VAL_2) || ((X) == ENUM_6_VAL_3) || ((X) == ENUM_6_VAL_4) || ((X) == ENUM_6_VAL_5) || ((X) == ENUM_6_VAL_6) || ((X) == ENUM_6_VAL_7) || ((X) == ENUM_6_VAL_8) || ((X) == ENUM_6_VAL_9))
#define IS_ENUM_7(X) (((X) == ENUM_7_VAL_0) || ((X) == ENUM_7_VAL_1) || ((X) == ENUM_7_VAL_2) || ((X) == ENUM_7_VAL_3) || ((X) == ENUM_7_VAL_4) || ((X) == ENUM_7_VAL_5) || ((X) == ENUM_7_VAL_6) || ((X) == ENUM_7_VAL_7) || ((X) == ENUM_7_VAL_8) || ((X) == ENUM_7_VAL_9))
#define IS_ENUM_8(X) (((X) == ENUM_8_VAL_0) || ((X) == ENUM_8_VAL_1) || ((X) == ENUM_8_VAL_2) || ((X) == ENUM_8_VAL_3) || ((X) == ENUM_8_VAL_4) || ((X) == ENUM_8_VAL_5) || ((X) == ENUM_8_VAL_6) || ((X) == ENUM_8_VAL_7) || ((X) == ENUM_8_VAL_8) || ((X) == ENUM_8_VAL_9))
#define IS_ENUM_9(X) (((X) == ENUM_9_VAL_0) || ((X) == ENUM_9_VAL_1) || ((X) == ENUM_9_VAL_2) || ((X) == ENUM_9_VAL_3) || ((X) == ENUM_9_VAL_4) || ((X) == ENUM_9_VAL_5) || ((X) == ENUM_9_VAL_6) || ((X) == ENUM_9_VAL_7) || ((X) == ENUM_9_VAL_8) || ((X) == ENUM_9_VAL_9))
#define IS_ENUM_10(X) (((X) == ENUM_10_VAL_0) || ((X) == ENUM_10_VAL_1) || ((X) == ENUM_10_VAL_2) || ((X) == ENUM_10_VAL_3) || ((X) == ENUM_10_VAL_4) || ((X) == ENUM_10_VAL_5) || ((X) == ENUM_10_VAL_6) || ((X) == ENUM_10_VAL_7) || ((X) == ENUM_10_VAL_8) || ((X) == ENUM_10_VAL_9))
#define IS_ENUM_11(X) (((X) == ENUM_11_VAL_0) || ((X) == ENUM_11_VAL_1) || ((X) == ENUM_11_VAL_2) || ((X) == ENUM_11_VAL_3) || ((X) == ENUM_11_VAL_4) || ((X) == ENUM_11_VAL_5) || ((X) == ENUM_11_VAL_6) || ((X) == ENUM_11_VAL_7) || ((X) == ENUM_11_VAL_8) || ((X) == ENUM_11_VAL_9))
#define IS_ENUM_12(X) (((X) == ENUM_12_VAL_0) || ((X) == ENUM_12_VAL_1) || ((X) == ENUM_12_VAL_2) || ((X) == ENUM_12_VAL_3) || ((X) == ENUM_12_VAL_4) || ((X) == ENUM_12_VAL_5) || ((X) == ENUM_12_VAL_6) || ((X) == ENUM_12_VAL_7) || ((X) == ENUM_12_VAL_8) || ((X) == ENUM_12_VAL_9))
#define IS_ENUM_13(X) (((X) == ENUM_13_VAL_0) || ((X) == ENUM_13_VAL_1) || ((X) == ENUM_13_VAL_2) || ((X) == ENUM_13_VAL_3) || ((X) == ENUM_13_VAL_4) || ((X) == ENUM_13_VAL_5) || ((X) == ENUM_13_VAL_6) || ((X) == ENUM_13_VAL_7) || ((X) == ENUM_13_VAL_8) || ((X) == ENUM_13_VAL_9))
#define IS_ENUM_14(X) (((X) == ENUM_14_VAL_0) || ((X) == ENUM_14_VAL_1) || ((X) == ENUM_14_VAL_2) || ((X) == ENUM_14_VAL_3) || ((X) == ENUM_14_VAL_4) || ((X) == ENUM_14_VAL_5) || ((X) == ENUM_14_VAL_6) || ((X) == ENUM_14_VAL_7) || ((X) == ENUM_14_VAL_8) || ((X) == ENUM_14_VAL_9))
#define IS_ENUM_15(X) (((X) == ENUM_15_VAL_0) || ((X) == ENUM_15_VAL_1) || ((X) == ENUM_15_VAL_2) || ((X) == ENUM_15_VAL_3) || ((X) == ENUM_15_VAL_4) || ((X) == ENUM_15_VAL_5) || ((X) == ENUM_15_VAL_6) || ((X) == ENUM_15_VAL_7) || ((X) == ENUM_15_VAL_8) || ((X) == ENUM_15_VAL_9))
#define IS_ENUM_16(X) (((X) == ENUM_16_VAL_0) || ((X) == ENUM_16_VAL_1) || ((X) == ENUM_16_VAL_2) || ((X) == ENUM_16_VAL_3) || ((X) == ENUM_16_VAL_4) || ((X) == ENUM_16_VAL_5) || ((X) == ENUM_16_VAL_6) || ((X) == ENUM_16_VAL_7) || ((X) == ENUM_16_VAL_8) || ((X) == ENUM_16_VAL_9))
#define IS_ENUM_17(X) (((X) == ENUM_17_VAL_0) || ((X) == ENUM_17_VAL_1) || ((X) == ENUM_17_VAL_2) || ((X) == ENUM_17_VAL_3) || ((X) == ENUM_17_VAL_4) || ((X) == ENUM_17_VAL_5) || ((X) == ENUM_17_VAL_6) || ((X) == ENUM_17_VAL_7) || ((X) == ENUM_17_VAL_8) || ((X) == ENUM_17_VAL_9))
#define IS_ENUM_18(X) (((X) == ENUM_18_VAL_0) || ((X) == ENUM_18_VAL_1) || ((X) == ENUM_18_VAL_2) || ((X) == ENUM_18_VAL_3) || ((X) == ENUM_18_VAL_4) || ((X) == ENUM_18_VAL_5) || ((X) == ENUM_18_VAL_6) || ((X) == ENUM_18_VAL_7) || ((X) == ENUM_18_VAL_8) || ((X) == ENUM_18_VAL_9))
#define IS_ENUM_19(X) (((X) == ENUM_19_VAL_0) || ((X) == ENUM_19_VAL_1) || ((X) == ENUM_19_VAL_2) || ((X) == ENUM_19_VAL_3) || ((X) == ENUM_19_VAL_4) || ((X) == ENUM_19_VAL_5) || ((X) == ENUM_19_VAL_6) || ((X) == ENUM_19_VAL_7) || ((X) == ENUM_19_VAL_8) || ((X) == ENUM_19_VAL_9))
#define IS_ENUM_20(X) (((X) == ENUM_20_VAL_0) || ((X) == ENUM_20_VAL_1) || ((X) == ENUM_20_VAL_2) || ((X) == ENUM_20_VAL_3) || ((X) == ENUM_20_VAL_4) || ((X) == ENUM_20_VAL_5) || ((X) == ENUM_20_VAL_6) || ((X) == ENUM_20_VAL_7) || ((X) == ENUM_20_VAL_8) || ((X) == ENUM_20_VAL_9))
#define IS_ENUM_21(X) (((X) == ENUM_21_VAL_0) || ((X) == ENUM_21_VAL_1) || ((X) == ENUM_21_VAL_2) || ((X) == ENUM_21_VAL_3) || ((X) == ENUM_21_VAL_4) || ((X) == ENUM_21_VAL_5) || ((X) == ENUM_21_VAL_6) || ((X) == ENUM_21_VAL_7) || ((X) == ENUM_21_VAL_8) || ((X) == ENUM_21_VAL_9))
#define IS_ENUM_22(X) (((X) == ENUM_22_VAL_0) || ((X) == ENUM_22_VAL_1) || ((X) == ENUM_22_VAL_2) || ((X) == ENUM_22_VAL_3) || ((X) == ENUM_22_VAL_4) || ((X) == ENUM_22_VAL_5) || ((X) == ENUM_22_VAL_6) || ((X) == ENUM_22_VAL_7) || ((X) == ENUM_22_VAL_8) || ((X) == ENUM_22_VAL_9))
#define IS_ENUM_23(X) (((X) == ENUM_23_VAL_0) || ((X) == ENUM_23_VAL_1) || ((X) == ENUM_23_VAL_2) || ((X) == ENUM_23_VAL_3) || ((X) == ENUM_23_VAL_4) || ((X) == ENUM_23_VAL_5) || ((X) == ENUM_23_VAL_6) || ((X) == ENUM_23_VAL_7) || ((X) == ENUM_23_VAL_8) || ((X) == ENUM_23_VAL_9))
#define IS_ENUM_24(X) (((X) == ENUM_24_VAL_0) || ((X) == ENUM_24_VAL_1) || ((X) == ENUM_24_VAL_2) || ((X) == ENUM_24_VAL_3) || ((X) == ENUM_24_VAL_4) || ((X) == ENUM_24_VAL_5) || ((X) == ENUM_24_VAL_6) || ((X) == ENUM_24_VAL_7) || ((X) == ENUM_24_VAL_8) || ((X) == ENUM_24_VAL_9))
#define IS_ENUM_25(X) (((X) == ENUM_25_VAL_0) || ((X) == ENUM_25_VAL_1) || ((X) == ENUM_25_VAL_2) || ((X) == ENUM_25_VAL_3) || ((X) == ENUM_25_VAL_4) || ((X) == ENUM_25_VAL_5) || ((X) == ENUM_25_VAL_6) || ((X) == ENUM_25_VAL_7) || ((X) == ENUM_25_VAL_8) || ((X) == ENUM_25_VAL_9))
#define IS_ENUM_26(X) (((X) == ENUM_26_VAL_0) || ((X) == ENUM_26_VAL_1) || ((X) == ENUM_26_VAL_2) || ((X) == ENUM_26_VAL_3) || ((X) == ENUM_26_VAL_4) || ((X) == ENUM_26_VAL_5) || ((X) == ENUM_26_VAL_6) || ((X) == ENUM_26_VAL_7) || ((X) == ENUM_26_VAL_8) || ((X) == ENUM_26_VAL_9))
#define IS_ENUM_27(X) (((X) == ENUM_27_VAL_0) || ((X) == ENUM_27_VAL_1) || ((X) == ENUM_27_VAL_2) || ((X) == ENUM_27_VAL_3) || ((X) == ENUM_27_VAL_4) || ((X) == ENUM_27_VAL_5) || ((X) == ENUM_27_VAL_6) || ((X) == ENUM_27_VAL_7) || ((X) == ENUM_27_VAL_8) || ((X) == ENUM_27_VAL_9))
#define IS_ENUM_28(X) (((X) == ENUM_28_VAL_0) || ((X) == ENUM_28_VAL_1) || ((X) == ENUM_28_VAL_2) || ((X) == ENUM_28_VAL_3) || ((X) == ENUM_28_VAL_4) || ((X) == ENUM_28_VAL_5) || ((X) == ENUM_28_VAL_6) || ((X) == ENUM_28_VAL_7) || ((X) == ENUM_28_VAL_8) || ((X) == ENUM_28_VAL_9))
#define IS_ENUM_29(X) (((X) == ENUM_29_VAL_0) || ((X) == ENUM_29_VAL_1) || ((X) == ENUM_29_VAL_2) || ((X) == ENUM_29_VAL_3) || ((X) == ENUM_29_VAL_4) || ((X) == ENUM_29_VAL_5) || ((X) == ENUM_29_VAL_6) || ((X) == ENUM_29_VAL_7) || ((X) == ENUM_29_VAL_8) || ((X) == ENUM_29_VAL_9))
class CREG_0 : public CRegister<0x48000000UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_75 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_1 : public CRegister<0x48000004UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_65 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_2 : public CRegister<0x48000008UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_18 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_3 : public CRegister<0x4800000cUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_77 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_4 : public CRegister<0x48000010UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_5 : public CRegister<0x48000014UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_99 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_6 : public CRegister<0x48000018UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_25 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_7 : public CRegister<0x4800001cUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_14 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_8 : public CRegister<0x48000020UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_59 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_9 : public CRegister<0x48000024UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_23 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_10 : public CRegister<0x48000028UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_36 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_11 : public CRegister<0x4800002cUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_97 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_12 : public CRegister<0x48000030UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_84 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_13 : public CRegister<0x48000034UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_61 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_14 : public CRegister<0x48000038UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_36 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_15 : public CRegister<0x4800003cUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_25 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_16 : public CRegister<0x48000040UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_17 : public CRegister<0x48000044UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_46 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_18 : public CRegister<0x48000048UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_44 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_19 : public CRegister<0x4800004cUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_46 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_20 : public CRegister<0x48000050UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_15 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_21 : public CRegister<0x48000054UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_41 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_22 : public CRegister<0x48000058UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_83 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_23 : public CRegister<0x4800005cUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_55 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_24 : public CRegister<0x48000060UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_88 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_25 : public CRegister<0x48000064UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_57 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_26 : public CRegister<0x48000068UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_55 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_27 : public CRegister<0x4800006cUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_13 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_28 : public CRegister<0x48000070UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_29 : public CRegister<0x48000074UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_61 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_30 : public CRegister<0x48000078UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_6 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_31 : public CRegister<0x4800007cUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_25 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_32 : public CRegister<0x48000080UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_31 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_33 : public CRegister<0x48000084UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_50 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_34 : public CRegister<0x48000088UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_41 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_35 : public CRegister<0x4800008cUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_30 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_36 : public CRegister<0x48000090UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_97 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_37 : public CRegister<0x48000094UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_26 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_38 : public CRegister<0x48000098UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_95 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_39 : public CRegister<0x4800009cUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_78 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_40 : public CRegister<0x480000a0UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_7 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_41 : public CRegister<0x480000a4UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_18 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_42 : public CRegister<0x480000a8UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_0 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_43 : public CRegister<0x480000acUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_76 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_44 : public CRegister<0x480000b0UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_14 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_45 : public CRegister<0x480000b4UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_76 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_46 : public CRegister<0x480000b8UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_88 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_47 : public CRegister<0x480000bcUL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_34 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_48 : public CRegister<0x480000c0UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_35 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_49 : public CRegister<0x480000c4UL> {
private:
    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_14 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
typedef struct {
    ENUM_17 ST_0_member_0;
    ENUM_11 ST_0_member_1;
    ENUM_28 ST_0_member_2;
    ENUM_2 ST_0_member_3;
    ENUM_8 ST_0_member_4;
    ENUM_18 ST_0_member_5;
    ENUM_28 ST_0_member_6;
    ENUM_9 ST_0_member_7;
    ENUM_11 ST_0_member_8;
    ENUM_22 ST_0_member_9;
} ST_0;
typedef struct {
    ENUM_24 ST_1_member_0;
    ENUM_15 ST_1_member_1;
    ENUM_15 ST_1_member_2;
    int ST_1_member_3;
    ENUM_26 ST_1_member_4;
    ENUM_28 ST_1_member_5;
    uint32_t ST_1_member_6;
    ENUM_28 ST_1_member_7;
    ENUM_7 ST_1_member_8;
    uint32_t ST_1_member_9;
} ST_1;
typedef struct {
    ENUM_18 ST_2_member_0;
    ENUM_8 ST_2_member_1;
    ENUM_0 ST_2_member_2;
    ENUM_27 ST_2_member_3;
    ENUM_11 ST_2_member_4;
    ENUM_23 ST_2_member_5;
    ENUM_21 ST_2_member_6;
    ENUM_16 ST_2_member_7;
    ENUM_8 ST_2_member_8;
    ENUM_18 ST_2_member_9;
} ST_2;
typedef struct {
    ENUM_8 ST_3_member_0;
    ENUM_2 ST_3_member_1;
    int ST_3_member_2;
    ENUM_12 ST_3_member_3;
    ENUM_3 ST_3_member_4;
    int ST_3_member_5;
    ENUM_28 ST_3_member_6;
    ENUM_16 ST_3_member_7;
    ENUM_17 ST_3_member_8;
    uint32_t ST_3_member_9;
} ST_3;
typedef struct {
    ENUM_23 ST_4_member_0;
    ENUM_1 ST_4_member_1;
    ENUM_0 ST_4_member_2;
    ENUM_15 ST_4_member_3;
    ENUM_0 ST_4_member_4;
    ENUM_9 ST_4_member_5;
    int ST_4_member_6;
    ENUM_29 ST_4_member_7;
    ENUM_17 ST_4_member_8;
    ENUM_17 ST_4_member_9;
} ST_4;
typedef struct {
    ENUM_26 ST_5_member_0;
    ENUM_26 ST_5_member_1;
    ENUM_23 ST_5_member_2;
    ENUM_29 ST_5_member_3;
    ENUM_4 ST_5_member_4;
    ENUM_4 ST_5_member_5;
    ENUM_12 ST_5_member_6;
    ENUM_10 ST_5_member_7;
    ENUM_14 ST_5_member_8;
    ENUM_26 ST_5_member_9;
} ST_5;
typedef struct {
    ENUM_3 ST_6_member_0;
    ENUM_2 ST_6_member_1;
    ENUM_0 ST_6_member_2;
    ENUM_22 ST_6_member_3;
    uint8_t ST_6_member_4;
    ENUM_9 ST_6_member_5;
    ENUM_5 ST_6_member_6;
    int ST_6_member_7;
    ENUM_25 ST_6_member_8;
    ENUM_26 ST_6_member_9;
} ST_6;
typedef struct {
    ENUM_27 ST_7_member_0;
    ENUM_1 ST_7_member_1;
    ENUM_6 ST_7_member_2;
    ENUM_5 ST_7_member_3;
    ENUM_19 ST_7_member_4;
    ENUM_27 ST_7_member_5;
    ENUM_7 ST_7_member_6;
    ENUM_29 ST_7_member_7;
    uint16_t ST_7_member_8;
    ENUM_20 ST_7_member_9;
} ST_7;
typedef struct {
    ENUM_13 ST_8_member_0;
    ENUM_24 ST_8_member_1;
    ENUM_21 ST_8_member_2;
    ENUM_7 ST_8_member_3;
    ENUM_9 ST_8_member_4;
    ENUM_10 ST_8_member_5;
    uint16_t ST_8_member_6;
    ENUM_8 ST_8_member_7;
    ENUM_22 ST_8_member_8;
    ENUM_21 ST_8_member_9;
} ST_8;
typedef struct {
    ENUM_7 ST_9_member_0;
    ENUM_26 ST_9_member_1;
    ENUM_4 ST_9_member_2;
    ENUM_22 ST_9_member_3;
    ENUM_19 ST_9_member_4;
    ENUM_10 ST_9_member_5;
    ENUM_10 ST_9_member_6;
    ENUM_26 ST_9_member_7;
    ENUM_18 ST_9_member_8;
    ENUM_23 ST_9_member_9;
} ST_9;
typedef struct {
    ENUM_17 ST_10_member_0;
    ENUM_2 ST_10_member_1;
    ENUM_3 ST_10_member_2;
    ENUM_1 ST_10_member_3;
    ENUM_22 ST_10_member_4;
    ENUM_19 ST_10_member_5;
    uint32_t ST_10_member_6;
    ENUM_12 ST_10_member_7;
    ENUM_21 ST_10_member_8;
    ENUM_27 ST_10_member_9;
} ST_10;
typedef struct {
    ENUM_21 ST_11_member_0;
    ENUM_17 ST_11_member_1;
    ENUM_29 ST_11_member_2;
    ENUM_11 ST_11_member_3;
    ENUM_1 ST_11_member_4;
    ENUM_9 ST_11_member_5;
    ENUM_1 ST_11_member_6;
    ENUM_22 ST_11_member_7;
    ENUM_17 ST_11_member_8;
    ENUM_25 ST_11_member_9;
} ST_11;
typedef struct {
    ENUM_2 ST_12_member_0;
    ENUM_10 ST_12_member_1;
    ENUM_7 ST_12_member_2;
    ENUM_9 ST_12_member_3;
    ENUM_7 ST_12_member_4;
    ENUM_27 ST_12_member_5;
    ENUM_7 ST_12_member_6;
    ENUM_4 ST_12_member_7;
    ENUM_18 ST_12_member_8;
    ENUM_20 ST_12_member_9;
} ST_12;
typedef struct {
    ENUM_20 ST_13_member_0;
    ENUM_26 ST_13_member_1;
    ENUM_28 ST_13_member_2;
    uint32_t ST_13_member_3;
    ENUM_21 ST_13_member_4;
    ENUM_15 ST_13_member_5;
    ENUM_21 ST_13_member_6;
    uint8_t ST_13_member_7;
    ENUM_23 ST_13_member_8;
    ENUM_20 ST_13_member_9;
} ST_13;
typedef struct {
    ENUM_16 ST_14_member_0;
    ENUM_14 ST_14_member_1;
    ENUM_26 ST_14_member_2;
    ENUM_27 ST_14_member_3;
    ENUM_16 ST_14_member_4;
    ENUM_13 ST_14_member_5;
    ENUM_12 ST_14_member_6;
    ENUM_4 ST_14_member_7;
    ENUM_10 ST_14_member_8;
    ENUM_22 ST_14_member_9;
} ST_14;
typedef struct {
    ENUM_14 ST_15_member_0;
    ENUM_0 ST_15_member_1;
    ENUM_18 ST_15_member_2;
    ENUM_5 ST_15_member_3;
    ENUM_13 ST_15_member_4;
    ENUM_10 ST_15_member_5;
    ENUM_27 ST_15_member_6;
    ENUM_12 ST_15_member_7;
    ENUM_11 ST_15_member_8;
    ENUM_24 ST_15_member_9;
} ST_15;
typedef struct {
    ENUM_7 ST_16_member_0;
    uint16_t ST_16_member_1;
    ENUM_2 ST_16_member_2;
    ENUM_17 ST_16_member_3;
    int ST_16_member_4;
    ENUM_11 ST_16_member_5;
    ENUM_9 ST_16_member_6;
    ENUM_10 ST_16_member_7;
    ENUM_11 ST_16_member_8;
    ENUM_2 ST_16_member_9;
} ST_16;
typedef struct {
    ENUM_19 ST_17_member_0;
    uint8_t ST_17_member_1;
    ENUM_14 ST_17_member_2;
    ENUM_5 ST_17_member_3;
    ENUM_5 ST_17_member_4;
    ENUM_1 ST_17_member_5;
    ENUM_10 ST_17_member_6;
    ENUM_5 ST_17_member_7;
    ENUM_13 ST_17_member_8;
    ENUM_16 ST_17_member_9;
} ST_17;
typedef struct {
    ENUM_1 ST_18_member_0;
    ENUM_9 ST_18_member_1;
    ENUM_4 ST_18_member_2;
    ENUM_6 ST_18_member_3;
    ENUM_16 ST_18_member_4;
    ENUM_9 ST_18_member_5;
    ENUM_10 ST_18_member_6;
    ENUM_12 ST_18_member_7;
    int ST_18_member_8;
    uint8_t ST_18_member_9;
} ST_18;
typedef struct {
    ENUM_11 ST_19_member_0;
    ENUM_20 ST_19_member_1;
    ENUM_6 ST_19_member_2;
    ENUM_11 ST_19_member_3;
    int ST_19_member_4;
    ENUM_12 ST_19_member_5;
    ENUM_5 ST_19_member_6;
    uint16_t ST_19_member_7;
    ENUM_12 ST_19_member_8;
    ENUM_0 ST_19_member_9;
} ST_19;
void hal_func_0(ST_18* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_1(param->ST_18_member_0)) { return; }
    if (!IS_ENUM_9(param->ST_18_member_1)) { return; }
    if (!IS_ENUM_4(param->ST_18_member_2)) { return; }
    if (!IS_ENUM_6(param->ST_18_member_3)) { return; }
    if (!IS_ENUM_16(param->ST_18_member_4)) { return; }
    if (!IS_ENUM_9(param->ST_18_member_5)) { return; }
    if (!IS_ENUM_10(param->ST_18_member_6)) { return; }
    if (!IS_ENUM_12(param->ST_18_member_7)) { return; }
    if (param->ST_18_member_6 == ENUM_10_VAL_4) {
        __attribute__((unused)) ENUM_16 val = param->ST_18_member_4;
        __attribute__((unused)) uint8_t shift = param->ST_18_member_9;
        CREG_40::configure(shift, val);
    }
}
void hal_func_1(ST_18* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_1(param->ST_18_member_0)) { return; }
    if (!IS_ENUM_9(param->ST_18_member_1)) { return; }
    if (!IS_ENUM_4(param->ST_18_member_2)) { return; }
    if (!IS_ENUM_6(param->ST_18_member_3)) { return; }
    if (!IS_ENUM_16(param->ST_18_member_4)) { return; }
    if (!IS_ENUM_9(param->ST_18_member_5)) { return; }
    if (!IS_ENUM_10(param->ST_18_member_6)) { return; }
    if (!IS_ENUM_12(param->ST_18_member_7)) { return; }
    if (param->ST_18_member_3 == ENUM_6_VAL_2) {
        __attribute__((unused)) ENUM_10 val = param->ST_18_member_6;
        __attribute__((unused)) ENUM_6 shift = param->ST_18_member_3;
        CREG_21::configure(shift, val);
        CREG_14::configure(shift, val);
        CREG_2::configure(shift, val);
        CREG_38::configure(shift, val);
        CREG_9::configure(shift, val);
    }
    if (param->ST_18_member_7 == ENUM_12_VAL_6) {
        __attribute__((unused)) ENUM_4 val = param->ST_18_member_2;
        __attribute__((unused)) ENUM_9 shift = param->ST_18_member_1;
        CREG_31::configure(shift, val);
        CREG_33::configure(shift, val);
        CREG_38::configure(shift, val);
    }
    if (param->ST_18_member_4 == ENUM_16_VAL_4) {
        __attribute__((unused)) int val = param->ST_18_member_8;
        __attribute__((unused)) ENUM_4 shift = param->ST_18_member_2;
        CREG_25::configure(shift, val);
    }
    if (param->ST_18_member_3 == ENUM_6_VAL_0) {
        __attribute__((unused)) ENUM_16 val = param->ST_18_member_4;
        __attribute__((unused)) ENUM_9 shift = param->ST_18_member_1;
        CREG_24::configure(shift, val);
        CREG_43::configure(shift, val);
        CREG_38::configure(shift, val);
    }
}
void hal_func_2(ST_14* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_16(param->ST_14_member_0)) { return; }
    if (!IS_ENUM_14(param->ST_14_member_1)) { return; }
    if (!IS_ENUM_26(param->ST_14_member_2)) { return; }
    if (!IS_ENUM_27(param->ST_14_member_3)) { return; }
    if (!IS_ENUM_16(param->ST_14_member_4)) { return; }
    if (!IS_ENUM_13(param->ST_14_member_5)) { return; }
    if (!IS_ENUM_12(param->ST_14_member_6)) { return; }
    if (!IS_ENUM_4(param->ST_14_member_7)) { return; }
    if (!IS_ENUM_10(param->ST_14_member_8)) { return; }
    if (!IS_ENUM_22(param->ST_14_member_9)) { return; }
    if (param->ST_14_member_9 == ENUM_22_VAL_2) {
        __attribute__((unused)) ENUM_13 val = param->ST_14_member_5;
        __attribute__((unused)) ENUM_12 shift = param->ST_14_member_6;
        CREG_37::configure(shift, val);
        CREG_21::configure(shift, val);
        CREG_47::configure(shift, val);
    }
    if (param->ST_14_member_1 == ENUM_14_VAL_3) {
        __attribute__((unused)) ENUM_13 val = param->ST_14_member_5;
        __attribute__((unused)) ENUM_10 shift = param->ST_14_member_8;
        CREG_9::configure(shift, val);
        CREG_1::configure(shift, val);
        CREG_1::configure(shift, val);
    }
    if (param->ST_14_member_0 == ENUM_16_VAL_2) {
        __attribute__((unused)) ENUM_16 val = param->ST_14_member_0;
        __attribute__((unused)) ENUM_4 shift = param->ST_14_member_7;
        CREG_7::configure(shift, val);
    }
    if (param->ST_14_member_6 == ENUM_12_VAL_5) {
        __attribute__((unused)) ENUM_4 val = param->ST_14_member_7;
        __attribute__((unused)) ENUM_16 shift = param->ST_14_member_4;
        CREG_26::configure(shift, val);
        CREG_42::configure(shift, val);
        CREG_46::configure(shift, val);
        CREG_36::configure(shift, val);
        CREG_47::configure(shift, val);
    }
}
void hal_func_3(ST_1* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_24(param->ST_1_member_0)) { return; }
    if (!IS_ENUM_15(param->ST_1_member_1)) { return; }
    if (!IS_ENUM_15(param->ST_1_member_2)) { return; }
    if (!IS_ENUM_26(param->ST_1_member_4)) { return; }
    if (!IS_ENUM_28(param->ST_1_member_5)) { return; }
    if (!IS_ENUM_28(param->ST_1_member_7)) { return; }
    if (!IS_ENUM_7(param->ST_1_member_8)) { return; }
    if (param->ST_1_member_7 == ENUM_28_VAL_9) {
        __attribute__((unused)) uint32_t val = param->ST_1_member_9;
        __attribute__((unused)) uint32_t shift = param->ST_1_member_6;
        CREG_1::configure(shift, val);
        CREG_18::configure(shift, val);
        CREG_11::configure(shift, val);
        CREG_38::configure(shift, val);
    }
    if (param->ST_1_member_5 == ENUM_28_VAL_3) {
        __attribute__((unused)) ENUM_7 val = param->ST_1_member_8;
        __attribute__((unused)) uint32_t shift = param->ST_1_member_6;
        CREG_1::configure(shift, val);
        CREG_22::configure(shift, val);
        CREG_15::configure(shift, val);
    }
    if (param->ST_1_member_4 == ENUM_26_VAL_0) {
        __attribute__((unused)) int val = param->ST_1_member_3;
        __attribute__((unused)) ENUM_26 shift = param->ST_1_member_4;
        CREG_29::configure(shift, val);
        CREG_32::configure(shift, val);
        CREG_7::configure(shift, val);
        CREG_41::configure(shift, val);
    }
    if (param->ST_1_member_2 == ENUM_15_VAL_6) {
        __attribute__((unused)) uint32_t val = param->ST_1_member_6;
        __attribute__((unused)) ENUM_15 shift = param->ST_1_member_2;
        CREG_34::configure(shift, val);
        CREG_49::configure(shift, val);
        CREG_10::configure(shift, val);
    }
}
void hal_func_4(ST_0* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_17(param->ST_0_member_0)) { return; }
    if (!IS_ENUM_11(param->ST_0_member_1)) { return; }
    if (!IS_ENUM_28(param->ST_0_member_2)) { return; }
    if (!IS_ENUM_2(param->ST_0_member_3)) { return; }
    if (!IS_ENUM_8(param->ST_0_member_4)) { return; }
    if (!IS_ENUM_18(param->ST_0_member_5)) { return; }
    if (!IS_ENUM_28(param->ST_0_member_6)) { return; }
    if (!IS_ENUM_9(param->ST_0_member_7)) { return; }
    if (!IS_ENUM_11(param->ST_0_member_8)) { return; }
    if (!IS_ENUM_22(param->ST_0_member_9)) { return; }
    if (param->ST_0_member_4 == ENUM_8_VAL_5) {
        __attribute__((unused)) ENUM_8 val = param->ST_0_member_4;
        __attribute__((unused)) ENUM_2 shift = param->ST_0_member_3;
        CREG_16::configure(shift, val);
        CREG_17::configure(shift, val);
    }
    if (param->ST_0_member_3 == ENUM_2_VAL_3) {
        __attribute__((unused)) ENUM_28 val = param->ST_0_member_6;
        __attribute__((unused)) ENUM_11 shift = param->ST_0_member_8;
        CREG_40::configure(shift, val);
    }
    if (param->ST_0_member_5 == ENUM_18_VAL_1) {
        __attribute__((unused)) ENUM_28 val = param->ST_0_member_2;
        __attribute__((unused)) ENUM_28 shift = param->ST_0_member_2;
        CREG_34::configure(shift, val);
        CREG_10::configure(shift, val);
        CREG_7::configure(shift, val);
        CREG_29::configure(shift, val);
    }
    if (param->ST_0_member_7 == ENUM_9_VAL_8) {
        __attribute__((unused)) ENUM_11 val = param->ST_0_member_8;
        __attribute__((unused)) ENUM_28 shift = param->ST_0_member_6;
        CREG_40::configure(shift, val);
        CREG_18::configure(shift, val);
        CREG_38::configure(shift, val);
    }
}
void hal_func_5(ST_5* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_26(param->ST_5_member_0)) { return; }
    if (!IS_ENUM_26(param->ST_5_member_1)) { return; }
    if (!IS_ENUM_23(param->ST_5_member_2)) { return; }
    if (!IS_ENUM_29(param->ST_5_member_3)) { return; }
    if (!IS_ENUM_4(param->ST_5_member_4)) { return; }
    if (!IS_ENUM_4(param->ST_5_member_5)) { return; }
    if (!IS_ENUM_12(param->ST_5_member_6)) { return; }
    if (!IS_ENUM_10(param->ST_5_member_7)) { return; }
    if (!IS_ENUM_14(param->ST_5_member_8)) { return; }
    if (!IS_ENUM_26(param->ST_5_member_9)) { return; }
    if (param->ST_5_member_3 == ENUM_29_VAL_5) {
        __attribute__((unused)) ENUM_4 val = param->ST_5_member_5;
        __attribute__((unused)) ENUM_23 shift = param->ST_5_member_2;
        CREG_20::configure(shift, val);
        CREG_46::configure(shift, val);
        CREG_1::configure(shift, val);
        CREG_37::configure(shift, val);
        CREG_3::configure(shift, val);
    }
    if (param->ST_5_member_5 == ENUM_4_VAL_3) {
        __attribute__((unused)) ENUM_26 val = param->ST_5_member_9;
        __attribute__((unused)) ENUM_12 shift = param->ST_5_member_6;
        CREG_19::configure(shift, val);
        CREG_8::configure(shift, val);
        CREG_2::configure(shift, val);
    }
    if (param->ST_5_member_2 == ENUM_23_VAL_7) {
        __attribute__((unused)) ENUM_23 val = param->ST_5_member_2;
        __attribute__((unused)) ENUM_12 shift = param->ST_5_member_6;
        CREG_44::configure(shift, val);
        CREG_28::configure(shift, val);
        CREG_20::configure(shift, val);
    }
    if (param->ST_5_member_7 == ENUM_10_VAL_5) {
        __attribute__((unused)) ENUM_4 val = param->ST_5_member_4;
        __attribute__((unused)) ENUM_26 shift = param->ST_5_member_9;
        CREG_33::configure(shift, val);
        CREG_39::configure(shift, val);
        CREG_7::configure(shift, val);
    }
}
void hal_func_6(ST_3* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_8(param->ST_3_member_0)) { return; }
    if (!IS_ENUM_2(param->ST_3_member_1)) { return; }
    if (!IS_ENUM_12(param->ST_3_member_3)) { return; }
    if (!IS_ENUM_3(param->ST_3_member_4)) { return; }
    if (!IS_ENUM_28(param->ST_3_member_6)) { return; }
    if (!IS_ENUM_16(param->ST_3_member_7)) { return; }
    if (!IS_ENUM_17(param->ST_3_member_8)) { return; }
    if (param->ST_3_member_0 == ENUM_8_VAL_6) {
        __attribute__((unused)) int val = param->ST_3_member_5;
        __attribute__((unused)) int shift = param->ST_3_member_2;
        CREG_10::configure(shift, val);
        CREG_7::configure(shift, val);
        CREG_27::configure(shift, val);
        CREG_34::configure(shift, val);
        CREG_42::configure(shift, val);
    }
    if (param->ST_3_member_7 == ENUM_16_VAL_4) {
        __attribute__((unused)) int val = param->ST_3_member_5;
        __attribute__((unused)) ENUM_8 shift = param->ST_3_member_0;
        CREG_2::configure(shift, val);
        CREG_20::configure(shift, val);
        CREG_0::configure(shift, val);
        CREG_47::configure(shift, val);
    }
    if (param->ST_3_member_7 == ENUM_16_VAL_9) {
        __attribute__((unused)) ENUM_3 val = param->ST_3_member_4;
        __attribute__((unused)) ENUM_2 shift = param->ST_3_member_1;
        CREG_43::configure(shift, val);
    }
    if (param->ST_3_member_8 == ENUM_17_VAL_9) {
        __attribute__((unused)) ENUM_28 val = param->ST_3_member_6;
        __attribute__((unused)) int shift = param->ST_3_member_2;
        CREG_36::configure(shift, val);
        CREG_7::configure(shift, val);
    }
}
void hal_func_7(ST_1* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_24(param->ST_1_member_0)) { return; }
    if (!IS_ENUM_15(param->ST_1_member_1)) { return; }
    if (!IS_ENUM_15(param->ST_1_member_2)) { return; }
    if (!IS_ENUM_26(param->ST_1_member_4)) { return; }
    if (!IS_ENUM_28(param->ST_1_member_5)) { return; }
    if (!IS_ENUM_28(param->ST_1_member_7)) { return; }
    if (!IS_ENUM_7(param->ST_1_member_8)) { return; }
    if (param->ST_1_member_7 == ENUM_28_VAL_4) {
        __attribute__((unused)) ENUM_15 val = param->ST_1_member_1;
        __attribute__((unused)) ENUM_15 shift = param->ST_1_member_1;
        CREG_17::configure(shift, val);
    }
    if (param->ST_1_member_7 == ENUM_28_VAL_3) {
        __attribute__((unused)) uint32_t val = param->ST_1_member_6;
        __attribute__((unused)) ENUM_15 shift = param->ST_1_member_2;
        CREG_7::configure(shift, val);
        CREG_13::configure(shift, val);
        CREG_44::configure(shift, val);
        CREG_3::configure(shift, val);
    }
    if (param->ST_1_member_2 == ENUM_15_VAL_1) {
        __attribute__((unused)) ENUM_24 val = param->ST_1_member_0;
        __attribute__((unused)) ENUM_15 shift = param->ST_1_member_1;
        CREG_22::configure(shift, val);
        CREG_3::configure(shift, val);
    }
}
void hal_func_8(ST_19* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_11(param->ST_19_member_0)) { return; }
    if (!IS_ENUM_20(param->ST_19_member_1)) { return; }
    if (!IS_ENUM_6(param->ST_19_member_2)) { return; }
    if (!IS_ENUM_11(param->ST_19_member_3)) { return; }
    if (!IS_ENUM_12(param->ST_19_member_5)) { return; }
    if (!IS_ENUM_5(param->ST_19_member_6)) { return; }
    if (!IS_ENUM_12(param->ST_19_member_8)) { return; }
    if (!IS_ENUM_0(param->ST_19_member_9)) { return; }
    if (param->ST_19_member_2 == ENUM_6_VAL_5) {
        __attribute__((unused)) ENUM_20 val = param->ST_19_member_1;
        __attribute__((unused)) ENUM_0 shift = param->ST_19_member_9;
        CREG_7::configure(shift, val);
        CREG_49::configure(shift, val);
        CREG_34::configure(shift, val);
        CREG_18::configure(shift, val);
    }
    if (param->ST_19_member_3 == ENUM_11_VAL_7) {
        __attribute__((unused)) ENUM_12 val = param->ST_19_member_5;
        __attribute__((unused)) ENUM_11 shift = param->ST_19_member_0;
        CREG_36::configure(shift, val);
    }
    if (param->ST_19_member_1 == ENUM_20_VAL_6) {
        __attribute__((unused)) ENUM_6 val = param->ST_19_member_2;
        __attribute__((unused)) ENUM_0 shift = param->ST_19_member_9;
        CREG_43::configure(shift, val);
        CREG_40::configure(shift, val);
    }
}
void hal_func_9(ST_7* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_27(param->ST_7_member_0)) { return; }
    if (!IS_ENUM_1(param->ST_7_member_1)) { return; }
    if (!IS_ENUM_6(param->ST_7_member_2)) { return; }
    if (!IS_ENUM_5(param->ST_7_member_3)) { return; }
    if (!IS_ENUM_19(param->ST_7_member_4)) { return; }
    if (!IS_ENUM_27(param->ST_7_member_5)) { return; }
    if (!IS_ENUM_7(param->ST_7_member_6)) { return; }
    if (!IS_ENUM_29(param->ST_7_member_7)) { return; }
    if (!IS_ENUM_20(param->ST_7_member_9)) { return; }
    if (param->ST_7_member_5 == ENUM_27_VAL_7) {
        __attribute__((unused)) ENUM_29 val = param->ST_7_member_7;
        __attribute__((unused)) ENUM_6 shift = param->ST_7_member_2;
        CREG_20::configure(shift, val);
        CREG_0::configure(shift, val);
    }
    if (param->ST_7_member_7 == ENUM_29_VAL_6) {
        __attribute__((unused)) ENUM_29 val = param->ST_7_member_7;
        __attribute__((unused)) ENUM_1 shift = param->ST_7_member_1;
        CREG_0::configure(shift, val);
        CREG_14::configure(shift, val);
        CREG_41::configure(shift, val);
    }
    if (param->ST_7_member_6 == ENUM_7_VAL_8) {
        __attribute__((unused)) ENUM_5 val = param->ST_7_member_3;
        __attribute__((unused)) uint16_t shift = param->ST_7_member_8;
        CREG_3::configure(shift, val);
        CREG_12::configure(shift, val);
        CREG_22::configure(shift, val);
        CREG_42::configure(shift, val);
    }
    if (param->ST_7_member_5 == ENUM_27_VAL_9) {
        __attribute__((unused)) ENUM_7 val = param->ST_7_member_6;
        __attribute__((unused)) ENUM_1 shift = param->ST_7_member_1;
        CREG_41::configure(shift, val);
        CREG_24::configure(shift, val);
        CREG_33::configure(shift, val);
        CREG_20::configure(shift, val);
    }
}
template <typename T>
concept Iclass_0 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_0 {
public:
    Cclass_0 () = default;
    int func_a () { return 1; }
    int func_b () { return 3; }
};
static_assert(Iclass_0<Cclass_0>);
template <Iclass_0 Tclass_0>
class Cclass_0_User {
private:
    Tclass_0* m_class { nullptr };
public:
    Cclass_0_User (Tclass_0* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_1 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_1 {
public:
    Cclass_1 () = default;
    int func_a () { return 2; }
    int func_b () { return 4; }
};
static_assert(Iclass_1<Cclass_1>);
template <Iclass_1 Tclass_1>
class Cclass_1_User {
private:
    Tclass_1* m_class { nullptr };
public:
    Cclass_1_User (Tclass_1* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_2 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_2 {
public:
    Cclass_2 () = default;
    int func_a () { return 3; }
    int func_b () { return 5; }
};
static_assert(Iclass_2<Cclass_2>);
template <Iclass_2 Tclass_2>
class Cclass_2_User {
private:
    Tclass_2* m_class { nullptr };
public:
    Cclass_2_User (Tclass_2* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_3 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_3 {
public:
    Cclass_3 () = default;
    int func_a () { return 4; }
    int func_b () { return 6; }
};
static_assert(Iclass_3<Cclass_3>);
template <Iclass_3 Tclass_3>
class Cclass_3_User {
private:
    Tclass_3* m_class { nullptr };
public:
    Cclass_3_User (Tclass_3* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_4 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_4 {
public:
    Cclass_4 () = default;
    int func_a () { return 5; }
    int func_b () { return 7; }
};
static_assert(Iclass_4<Cclass_4>);
template <Iclass_4 Tclass_4>
class Cclass_4_User {
private:
    Tclass_4* m_class { nullptr };
public:
    Cclass_4_User (Tclass_4* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_5 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_5 {
public:
    Cclass_5 () = default;
    int func_a () { return 6; }
    int func_b () { return 8; }
};
static_assert(Iclass_5<Cclass_5>);
template <Iclass_5 Tclass_5>
class Cclass_5_User {
private:
    Tclass_5* m_class { nullptr };
public:
    Cclass_5_User (Tclass_5* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_6 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_6 {
public:
    Cclass_6 () = default;
    int func_a () { return 7; }
    int func_b () { return 9; }
};
static_assert(Iclass_6<Cclass_6>);
template <Iclass_6 Tclass_6>
class Cclass_6_User {
private:
    Tclass_6* m_class { nullptr };
public:
    Cclass_6_User (Tclass_6* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_7 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_7 {
public:
    Cclass_7 () = default;
    int func_a () { return 8; }
    int func_b () { return 10; }
};
static_assert(Iclass_7<Cclass_7>);
template <Iclass_7 Tclass_7>
class Cclass_7_User {
private:
    Tclass_7* m_class { nullptr };
public:
    Cclass_7_User (Tclass_7* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_8 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_8 {
public:
    Cclass_8 () = default;
    int func_a () { return 9; }
    int func_b () { return 11; }
};
static_assert(Iclass_8<Cclass_8>);
template <Iclass_8 Tclass_8>
class Cclass_8_User {
private:
    Tclass_8* m_class { nullptr };
public:
    Cclass_8_User (Tclass_8* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_9 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_9 {
public:
    Cclass_9 () = default;
    int func_a () { return 10; }
    int func_b () { return 12; }
};
static_assert(Iclass_9<Cclass_9>);
template <Iclass_9 Tclass_9>
class Cclass_9_User {
private:
    Tclass_9* m_class { nullptr };
public:
    Cclass_9_User (Tclass_9* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_10 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_10 {
public:
    Cclass_10 () = default;
    int func_a () { return 11; }
    int func_b () { return 13; }
};
static_assert(Iclass_10<Cclass_10>);
template <Iclass_10 Tclass_10>
class Cclass_10_User {
private:
    Tclass_10* m_class { nullptr };
public:
    Cclass_10_User (Tclass_10* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_11 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_11 {
public:
    Cclass_11 () = default;
    int func_a () { return 12; }
    int func_b () { return 14; }
};
static_assert(Iclass_11<Cclass_11>);
template <Iclass_11 Tclass_11>
class Cclass_11_User {
private:
    Tclass_11* m_class { nullptr };
public:
    Cclass_11_User (Tclass_11* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_12 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_12 {
public:
    Cclass_12 () = default;
    int func_a () { return 13; }
    int func_b () { return 15; }
};
static_assert(Iclass_12<Cclass_12>);
template <Iclass_12 Tclass_12>
class Cclass_12_User {
private:
    Tclass_12* m_class { nullptr };
public:
    Cclass_12_User (Tclass_12* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_13 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_13 {
public:
    Cclass_13 () = default;
    int func_a () { return 14; }
    int func_b () { return 16; }
};
static_assert(Iclass_13<Cclass_13>);
template <Iclass_13 Tclass_13>
class Cclass_13_User {
private:
    Tclass_13* m_class { nullptr };
public:
    Cclass_13_User (Tclass_13* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_14 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_14 {
public:
    Cclass_14 () = default;
    int func_a () { return 15; }
    int func_b () { return 17; }
};
static_assert(Iclass_14<Cclass_14>);
template <Iclass_14 Tclass_14>
class Cclass_14_User {
private:
    Tclass_14* m_class { nullptr };
public:
    Cclass_14_User (Tclass_14* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_15 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_15 {
public:
    Cclass_15 () = default;
    int func_a () { return 16; }
    int func_b () { return 18; }
};
static_assert(Iclass_15<Cclass_15>);
template <Iclass_15 Tclass_15>
class Cclass_15_User {
private:
    Tclass_15* m_class { nullptr };
public:
    Cclass_15_User (Tclass_15* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_16 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_16 {
public:
    Cclass_16 () = default;
    int func_a () { return 17; }
    int func_b () { return 19; }
};
static_assert(Iclass_16<Cclass_16>);
template <Iclass_16 Tclass_16>
class Cclass_16_User {
private:
    Tclass_16* m_class { nullptr };
public:
    Cclass_16_User (Tclass_16* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_17 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_17 {
public:
    Cclass_17 () = default;
    int func_a () { return 18; }
    int func_b () { return 20; }
};
static_assert(Iclass_17<Cclass_17>);
template <Iclass_17 Tclass_17>
class Cclass_17_User {
private:
    Tclass_17* m_class { nullptr };
public:
    Cclass_17_User (Tclass_17* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_18 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_18 {
public:
    Cclass_18 () = default;
    int func_a () { return 19; }
    int func_b () { return 21; }
};
static_assert(Iclass_18<Cclass_18>);
template <Iclass_18 Tclass_18>
class Cclass_18_User {
private:
    Tclass_18* m_class { nullptr };
public:
    Cclass_18_User (Tclass_18* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_19 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_19 {
public:
    Cclass_19 () = default;
    int func_a () { return 20; }
    int func_b () { return 22; }
};
static_assert(Iclass_19<Cclass_19>);
template <Iclass_19 Tclass_19>
class Cclass_19_User {
private:
    Tclass_19* m_class { nullptr };
public:
    Cclass_19_User (Tclass_19* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_20 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_20 {
public:
    Cclass_20 () = default;
    int func_a () { return 21; }
    int func_b () { return 23; }
};
static_assert(Iclass_20<Cclass_20>);
template <Iclass_20 Tclass_20>
class Cclass_20_User {
private:
    Tclass_20* m_class { nullptr };
public:
    Cclass_20_User (Tclass_20* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_21 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_21 {
public:
    Cclass_21 () = default;
    int func_a () { return 22; }
    int func_b () { return 24; }
};
static_assert(Iclass_21<Cclass_21>);
template <Iclass_21 Tclass_21>
class Cclass_21_User {
private:
    Tclass_21* m_class { nullptr };
public:
    Cclass_21_User (Tclass_21* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_22 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_22 {
public:
    Cclass_22 () = default;
    int func_a () { return 23; }
    int func_b () { return 25; }
};
static_assert(Iclass_22<Cclass_22>);
template <Iclass_22 Tclass_22>
class Cclass_22_User {
private:
    Tclass_22* m_class { nullptr };
public:
    Cclass_22_User (Tclass_22* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_23 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_23 {
public:
    Cclass_23 () = default;
    int func_a () { return 24; }
    int func_b () { return 26; }
};
static_assert(Iclass_23<Cclass_23>);
template <Iclass_23 Tclass_23>
class Cclass_23_User {
private:
    Tclass_23* m_class { nullptr };
public:
    Cclass_23_User (Tclass_23* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_24 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_24 {
public:
    Cclass_24 () = default;
    int func_a () { return 25; }
    int func_b () { return 27; }
};
static_assert(Iclass_24<Cclass_24>);
template <Iclass_24 Tclass_24>
class Cclass_24_User {
private:
    Tclass_24* m_class { nullptr };
public:
    Cclass_24_User (Tclass_24* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_25 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_25 {
public:
    Cclass_25 () = default;
    int func_a () { return 26; }
    int func_b () { return 28; }
};
static_assert(Iclass_25<Cclass_25>);
template <Iclass_25 Tclass_25>
class Cclass_25_User {
private:
    Tclass_25* m_class { nullptr };
public:
    Cclass_25_User (Tclass_25* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_26 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_26 {
public:
    Cclass_26 () = default;
    int func_a () { return 27; }
    int func_b () { return 29; }
};
static_assert(Iclass_26<Cclass_26>);
template <Iclass_26 Tclass_26>
class Cclass_26_User {
private:
    Tclass_26* m_class { nullptr };
public:
    Cclass_26_User (Tclass_26* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_27 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_27 {
public:
    Cclass_27 () = default;
    int func_a () { return 28; }
    int func_b () { return 30; }
};
static_assert(Iclass_27<Cclass_27>);
template <Iclass_27 Tclass_27>
class Cclass_27_User {
private:
    Tclass_27* m_class { nullptr };
public:
    Cclass_27_User (Tclass_27* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_28 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_28 {
public:
    Cclass_28 () = default;
    int func_a () { return 29; }
    int func_b () { return 31; }
};
static_assert(Iclass_28<Cclass_28>);
template <Iclass_28 Tclass_28>
class Cclass_28_User {
private:
    Tclass_28* m_class { nullptr };
public:
    Cclass_28_User (Tclass_28* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_29 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_29 {
public:
    Cclass_29 () = default;
    int func_a () { return 30; }
    int func_b () { return 32; }
};
static_assert(Iclass_29<Cclass_29>);
template <Iclass_29 Tclass_29>
class Cclass_29_User {
private:
    Tclass_29* m_class { nullptr };
public:
    Cclass_29_User (Tclass_29* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_30 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_30 {
public:
    Cclass_30 () = default;
    int func_a () { return 31; }
    int func_b () { return 33; }
};
static_assert(Iclass_30<Cclass_30>);
template <Iclass_30 Tclass_30>
class Cclass_30_User {
private:
    Tclass_30* m_class { nullptr };
public:
    Cclass_30_User (Tclass_30* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_31 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_31 {
public:
    Cclass_31 () = default;
    int func_a () { return 32; }
    int func_b () { return 34; }
};
static_assert(Iclass_31<Cclass_31>);
template <Iclass_31 Tclass_31>
class Cclass_31_User {
private:
    Tclass_31* m_class { nullptr };
public:
    Cclass_31_User (Tclass_31* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_32 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_32 {
public:
    Cclass_32 () = default;
    int func_a () { return 33; }
    int func_b () { return 35; }
};
static_assert(Iclass_32<Cclass_32>);
template <Iclass_32 Tclass_32>
class Cclass_32_User {
private:
    Tclass_32* m_class { nullptr };
public:
    Cclass_32_User (Tclass_32* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_33 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_33 {
public:
    Cclass_33 () = default;
    int func_a () { return 34; }
    int func_b () { return 36; }
};
static_assert(Iclass_33<Cclass_33>);
template <Iclass_33 Tclass_33>
class Cclass_33_User {
private:
    Tclass_33* m_class { nullptr };
public:
    Cclass_33_User (Tclass_33* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_34 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_34 {
public:
    Cclass_34 () = default;
    int func_a () { return 35; }
    int func_b () { return 37; }
};
static_assert(Iclass_34<Cclass_34>);
template <Iclass_34 Tclass_34>
class Cclass_34_User {
private:
    Tclass_34* m_class { nullptr };
public:
    Cclass_34_User (Tclass_34* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_35 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_35 {
public:
    Cclass_35 () = default;
    int func_a () { return 36; }
    int func_b () { return 38; }
};
static_assert(Iclass_35<Cclass_35>);
template <Iclass_35 Tclass_35>
class Cclass_35_User {
private:
    Tclass_35* m_class { nullptr };
public:
    Cclass_35_User (Tclass_35* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_36 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_36 {
public:
    Cclass_36 () = default;
    int func_a () { return 37; }
    int func_b () { return 39; }
};
static_assert(Iclass_36<Cclass_36>);
template <Iclass_36 Tclass_36>
class Cclass_36_User {
private:
    Tclass_36* m_class { nullptr };
public:
    Cclass_36_User (Tclass_36* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_37 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_37 {
public:
    Cclass_37 () = default;
    int func_a () { return 38; }
    int func_b () { return 40; }
};
static_assert(Iclass_37<Cclass_37>);
template <Iclass_37 Tclass_37>
class Cclass_37_User {
private:
    Tclass_37* m_class { nullptr };
public:
    Cclass_37_User (Tclass_37* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_38 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_38 {
public:
    Cclass_38 () = default;
    int func_a () { return 39; }
    int func_b () { return 41; }
};
static_assert(Iclass_38<Cclass_38>);
template <Iclass_38 Tclass_38>
class Cclass_38_User {
private:
    Tclass_38* m_class { nullptr };
public:
    Cclass_38_User (Tclass_38* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_39 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_39 {
public:
    Cclass_39 () = default;
    int func_a () { return 40; }
    int func_b () { return 42; }
};
static_assert(Iclass_39<Cclass_39>);
template <Iclass_39 Tclass_39>
class Cclass_39_User {
private:
    Tclass_39* m_class { nullptr };
public:
    Cclass_39_User (Tclass_39* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_40 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_40 {
public:
    Cclass_40 () = default;
    int func_a () { return 41; }
    int func_b () { return 43; }
};
static_assert(Iclass_40<Cclass_40>);
template <Iclass_40 Tclass_40>
class Cclass_40_User {
private:
    Tclass_40* m_class { nullptr };
public:
    Cclass_40_User (Tclass_40* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_41 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_41 {
public:
    Cclass_41 () = default;
    int func_a () { return 42; }
    int func_b () { return 44; }
};
static_assert(Iclass_41<Cclass_41>);
template <Iclass_41 Tclass_41>
class Cclass_41_User {
private:
    Tclass_41* m_class { nullptr };
public:
    Cclass_41_User (Tclass_41* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_42 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_42 {
public:
    Cclass_42 () = default;
    int func_a () { return 43; }
    int func_b () { return 45; }
};
static_assert(Iclass_42<Cclass_42>);
template <Iclass_42 Tclass_42>
class Cclass_42_User {
private:
    Tclass_42* m_class { nullptr };
public:
    Cclass_42_User (Tclass_42* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_43 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_43 {
public:
    Cclass_43 () = default;
    int func_a () { return 44; }
    int func_b () { return 46; }
};
static_assert(Iclass_43<Cclass_43>);
template <Iclass_43 Tclass_43>
class Cclass_43_User {
private:
    Tclass_43* m_class { nullptr };
public:
    Cclass_43_User (Tclass_43* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_44 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_44 {
public:
    Cclass_44 () = default;
    int func_a () { return 45; }
    int func_b () { return 47; }
};
static_assert(Iclass_44<Cclass_44>);
template <Iclass_44 Tclass_44>
class Cclass_44_User {
private:
    Tclass_44* m_class { nullptr };
public:
    Cclass_44_User (Tclass_44* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_45 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_45 {
public:
    Cclass_45 () = default;
    int func_a () { return 46; }
    int func_b () { return 48; }
};
static_assert(Iclass_45<Cclass_45>);
template <Iclass_45 Tclass_45>
class Cclass_45_User {
private:
    Tclass_45* m_class { nullptr };
public:
    Cclass_45_User (Tclass_45* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_46 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_46 {
public:
    Cclass_46 () = default;
    int func_a () { return 47; }
    int func_b () { return 49; }
};
static_assert(Iclass_46<Cclass_46>);
template <Iclass_46 Tclass_46>
class Cclass_46_User {
private:
    Tclass_46* m_class { nullptr };
public:
    Cclass_46_User (Tclass_46* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_47 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_47 {
public:
    Cclass_47 () = default;
    int func_a () { return 48; }
    int func_b () { return 50; }
};
static_assert(Iclass_47<Cclass_47>);
template <Iclass_47 Tclass_47>
class Cclass_47_User {
private:
    Tclass_47* m_class { nullptr };
public:
    Cclass_47_User (Tclass_47* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_48 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_48 {
public:
    Cclass_48 () = default;
    int func_a () { return 49; }
    int func_b () { return 51; }
};
static_assert(Iclass_48<Cclass_48>);
template <Iclass_48 Tclass_48>
class Cclass_48_User {
private:
    Tclass_48* m_class { nullptr };
public:
    Cclass_48_User (Tclass_48* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_49 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_49 {
public:
    Cclass_49 () = default;
    int func_a () { return 50; }
    int func_b () { return 52; }
};
static_assert(Iclass_49<Cclass_49>);
template <Iclass_49 Tclass_49>
class Cclass_49_User {
private:
    Tclass_49* m_class { nullptr };
public:
    Cclass_49_User (Tclass_49* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_50 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_50 {
public:
    Cclass_50 () = default;
    int func_a () { return 51; }
    int func_b () { return 53; }
};
static_assert(Iclass_50<Cclass_50>);
template <Iclass_50 Tclass_50>
class Cclass_50_User {
private:
    Tclass_50* m_class { nullptr };
public:
    Cclass_50_User (Tclass_50* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_51 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_51 {
public:
    Cclass_51 () = default;
    int func_a () { return 52; }
    int func_b () { return 54; }
};
static_assert(Iclass_51<Cclass_51>);
template <Iclass_51 Tclass_51>
class Cclass_51_User {
private:
    Tclass_51* m_class { nullptr };
public:
    Cclass_51_User (Tclass_51* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_52 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_52 {
public:
    Cclass_52 () = default;
    int func_a () { return 53; }
    int func_b () { return 55; }
};
static_assert(Iclass_52<Cclass_52>);
template <Iclass_52 Tclass_52>
class Cclass_52_User {
private:
    Tclass_52* m_class { nullptr };
public:
    Cclass_52_User (Tclass_52* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_53 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_53 {
public:
    Cclass_53 () = default;
    int func_a () { return 54; }
    int func_b () { return 56; }
};
static_assert(Iclass_53<Cclass_53>);
template <Iclass_53 Tclass_53>
class Cclass_53_User {
private:
    Tclass_53* m_class { nullptr };
public:
    Cclass_53_User (Tclass_53* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_54 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_54 {
public:
    Cclass_54 () = default;
    int func_a () { return 55; }
    int func_b () { return 57; }
};
static_assert(Iclass_54<Cclass_54>);
template <Iclass_54 Tclass_54>
class Cclass_54_User {
private:
    Tclass_54* m_class { nullptr };
public:
    Cclass_54_User (Tclass_54* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_55 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_55 {
public:
    Cclass_55 () = default;
    int func_a () { return 56; }
    int func_b () { return 58; }
};
static_assert(Iclass_55<Cclass_55>);
template <Iclass_55 Tclass_55>
class Cclass_55_User {
private:
    Tclass_55* m_class { nullptr };
public:
    Cclass_55_User (Tclass_55* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_56 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_56 {
public:
    Cclass_56 () = default;
    int func_a () { return 57; }
    int func_b () { return 59; }
};
static_assert(Iclass_56<Cclass_56>);
template <Iclass_56 Tclass_56>
class Cclass_56_User {
private:
    Tclass_56* m_class { nullptr };
public:
    Cclass_56_User (Tclass_56* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_57 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_57 {
public:
    Cclass_57 () = default;
    int func_a () { return 58; }
    int func_b () { return 60; }
};
static_assert(Iclass_57<Cclass_57>);
template <Iclass_57 Tclass_57>
class Cclass_57_User {
private:
    Tclass_57* m_class { nullptr };
public:
    Cclass_57_User (Tclass_57* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_58 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_58 {
public:
    Cclass_58 () = default;
    int func_a () { return 59; }
    int func_b () { return 61; }
};
static_assert(Iclass_58<Cclass_58>);
template <Iclass_58 Tclass_58>
class Cclass_58_User {
private:
    Tclass_58* m_class { nullptr };
public:
    Cclass_58_User (Tclass_58* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_59 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_59 {
public:
    Cclass_59 () = default;
    int func_a () { return 60; }
    int func_b () { return 62; }
};
static_assert(Iclass_59<Cclass_59>);
template <Iclass_59 Tclass_59>
class Cclass_59_User {
private:
    Tclass_59* m_class { nullptr };
public:
    Cclass_59_User (Tclass_59* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_60 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_60 {
public:
    Cclass_60 () = default;
    int func_a () { return 61; }
    int func_b () { return 63; }
};
static_assert(Iclass_60<Cclass_60>);
template <Iclass_60 Tclass_60>
class Cclass_60_User {
private:
    Tclass_60* m_class { nullptr };
public:
    Cclass_60_User (Tclass_60* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_61 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_61 {
public:
    Cclass_61 () = default;
    int func_a () { return 62; }
    int func_b () { return 64; }
};
static_assert(Iclass_61<Cclass_61>);
template <Iclass_61 Tclass_61>
class Cclass_61_User {
private:
    Tclass_61* m_class { nullptr };
public:
    Cclass_61_User (Tclass_61* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_62 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_62 {
public:
    Cclass_62 () = default;
    int func_a () { return 63; }
    int func_b () { return 65; }
};
static_assert(Iclass_62<Cclass_62>);
template <Iclass_62 Tclass_62>
class Cclass_62_User {
private:
    Tclass_62* m_class { nullptr };
public:
    Cclass_62_User (Tclass_62* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_63 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_63 {
public:
    Cclass_63 () = default;
    int func_a () { return 64; }
    int func_b () { return 66; }
};
static_assert(Iclass_63<Cclass_63>);
template <Iclass_63 Tclass_63>
class Cclass_63_User {
private:
    Tclass_63* m_class { nullptr };
public:
    Cclass_63_User (Tclass_63* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_64 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_64 {
public:
    Cclass_64 () = default;
    int func_a () { return 65; }
    int func_b () { return 67; }
};
static_assert(Iclass_64<Cclass_64>);
template <Iclass_64 Tclass_64>
class Cclass_64_User {
private:
    Tclass_64* m_class { nullptr };
public:
    Cclass_64_User (Tclass_64* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_65 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_65 {
public:
    Cclass_65 () = default;
    int func_a () { return 66; }
    int func_b () { return 68; }
};
static_assert(Iclass_65<Cclass_65>);
template <Iclass_65 Tclass_65>
class Cclass_65_User {
private:
    Tclass_65* m_class { nullptr };
public:
    Cclass_65_User (Tclass_65* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_66 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_66 {
public:
    Cclass_66 () = default;
    int func_a () { return 67; }
    int func_b () { return 69; }
};
static_assert(Iclass_66<Cclass_66>);
template <Iclass_66 Tclass_66>
class Cclass_66_User {
private:
    Tclass_66* m_class { nullptr };
public:
    Cclass_66_User (Tclass_66* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_67 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_67 {
public:
    Cclass_67 () = default;
    int func_a () { return 68; }
    int func_b () { return 70; }
};
static_assert(Iclass_67<Cclass_67>);
template <Iclass_67 Tclass_67>
class Cclass_67_User {
private:
    Tclass_67* m_class { nullptr };
public:
    Cclass_67_User (Tclass_67* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_68 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_68 {
public:
    Cclass_68 () = default;
    int func_a () { return 69; }
    int func_b () { return 71; }
};
static_assert(Iclass_68<Cclass_68>);
template <Iclass_68 Tclass_68>
class Cclass_68_User {
private:
    Tclass_68* m_class { nullptr };
public:
    Cclass_68_User (Tclass_68* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_69 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_69 {
public:
    Cclass_69 () = default;
    int func_a () { return 70; }
    int func_b () { return 72; }
};
static_assert(Iclass_69<Cclass_69>);
template <Iclass_69 Tclass_69>
class Cclass_69_User {
private:
    Tclass_69* m_class { nullptr };
public:
    Cclass_69_User (Tclass_69* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_70 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_70 {
public:
    Cclass_70 () = default;
    int func_a () { return 71; }
    int func_b () { return 73; }
};
static_assert(Iclass_70<Cclass_70>);
template <Iclass_70 Tclass_70>
class Cclass_70_User {
private:
    Tclass_70* m_class { nullptr };
public:
    Cclass_70_User (Tclass_70* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_71 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_71 {
public:
    Cclass_71 () = default;
    int func_a () { return 72; }
    int func_b () { return 74; }
};
static_assert(Iclass_71<Cclass_71>);
template <Iclass_71 Tclass_71>
class Cclass_71_User {
private:
    Tclass_71* m_class { nullptr };
public:
    Cclass_71_User (Tclass_71* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_72 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_72 {
public:
    Cclass_72 () = default;
    int func_a () { return 73; }
    int func_b () { return 75; }
};
static_assert(Iclass_72<Cclass_72>);
template <Iclass_72 Tclass_72>
class Cclass_72_User {
private:
    Tclass_72* m_class { nullptr };
public:
    Cclass_72_User (Tclass_72* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_73 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_73 {
public:
    Cclass_73 () = default;
    int func_a () { return 74; }
    int func_b () { return 76; }
};
static_assert(Iclass_73<Cclass_73>);
template <Iclass_73 Tclass_73>
class Cclass_73_User {
private:
    Tclass_73* m_class { nullptr };
public:
    Cclass_73_User (Tclass_73* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_74 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_74 {
public:
    Cclass_74 () = default;
    int func_a () { return 75; }
    int func_b () { return 77; }
};
static_assert(Iclass_74<Cclass_74>);
template <Iclass_74 Tclass_74>
class Cclass_74_User {
private:
    Tclass_74* m_class { nullptr };
public:
    Cclass_74_User (Tclass_74* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_75 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_75 {
public:
    Cclass_75 () = default;
    int func_a () { return 76; }
    int func_b () { return 78; }
};
static_assert(Iclass_75<Cclass_75>);
template <Iclass_75 Tclass_75>
class Cclass_75_User {
private:
    Tclass_75* m_class { nullptr };
public:
    Cclass_75_User (Tclass_75* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_76 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_76 {
public:
    Cclass_76 () = default;
    int func_a () { return 77; }
    int func_b () { return 79; }
};
static_assert(Iclass_76<Cclass_76>);
template <Iclass_76 Tclass_76>
class Cclass_76_User {
private:
    Tclass_76* m_class { nullptr };
public:
    Cclass_76_User (Tclass_76* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_77 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_77 {
public:
    Cclass_77 () = default;
    int func_a () { return 78; }
    int func_b () { return 80; }
};
static_assert(Iclass_77<Cclass_77>);
template <Iclass_77 Tclass_77>
class Cclass_77_User {
private:
    Tclass_77* m_class { nullptr };
public:
    Cclass_77_User (Tclass_77* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_78 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_78 {
public:
    Cclass_78 () = default;
    int func_a () { return 79; }
    int func_b () { return 81; }
};
static_assert(Iclass_78<Cclass_78>);
template <Iclass_78 Tclass_78>
class Cclass_78_User {
private:
    Tclass_78* m_class { nullptr };
public:
    Cclass_78_User (Tclass_78* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_79 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_79 {
public:
    Cclass_79 () = default;
    int func_a () { return 80; }
    int func_b () { return 82; }
};
static_assert(Iclass_79<Cclass_79>);
template <Iclass_79 Tclass_79>
class Cclass_79_User {
private:
    Tclass_79* m_class { nullptr };
public:
    Cclass_79_User (Tclass_79* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_80 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_80 {
public:
    Cclass_80 () = default;
    int func_a () { return 81; }
    int func_b () { return 83; }
};
static_assert(Iclass_80<Cclass_80>);
template <Iclass_80 Tclass_80>
class Cclass_80_User {
private:
    Tclass_80* m_class { nullptr };
public:
    Cclass_80_User (Tclass_80* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_81 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_81 {
public:
    Cclass_81 () = default;
    int func_a () { return 82; }
    int func_b () { return 84; }
};
static_assert(Iclass_81<Cclass_81>);
template <Iclass_81 Tclass_81>
class Cclass_81_User {
private:
    Tclass_81* m_class { nullptr };
public:
    Cclass_81_User (Tclass_81* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_82 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_82 {
public:
    Cclass_82 () = default;
    int func_a () { return 83; }
    int func_b () { return 85; }
};
static_assert(Iclass_82<Cclass_82>);
template <Iclass_82 Tclass_82>
class Cclass_82_User {
private:
    Tclass_82* m_class { nullptr };
public:
    Cclass_82_User (Tclass_82* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_83 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_83 {
public:
    Cclass_83 () = default;
    int func_a () { return 84; }
    int func_b () { return 86; }
};
static_assert(Iclass_83<Cclass_83>);
template <Iclass_83 Tclass_83>
class Cclass_83_User {
private:
    Tclass_83* m_class { nullptr };
public:
    Cclass_83_User (Tclass_83* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_84 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_84 {
public:
    Cclass_84 () = default;
    int func_a () { return 85; }
    int func_b () { return 87; }
};
static_assert(Iclass_84<Cclass_84>);
template <Iclass_84 Tclass_84>
class Cclass_84_User {
private:
    Tclass_84* m_class { nullptr };
public:
    Cclass_84_User (Tclass_84* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_85 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_85 {
public:
    Cclass_85 () = default;
    int func_a () { return 86; }
    int func_b () { return 88; }
};
static_assert(Iclass_85<Cclass_85>);
template <Iclass_85 Tclass_85>
class Cclass_85_User {
private:
    Tclass_85* m_class { nullptr };
public:
    Cclass_85_User (Tclass_85* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_86 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_86 {
public:
    Cclass_86 () = default;
    int func_a () { return 87; }
    int func_b () { return 89; }
};
static_assert(Iclass_86<Cclass_86>);
template <Iclass_86 Tclass_86>
class Cclass_86_User {
private:
    Tclass_86* m_class { nullptr };
public:
    Cclass_86_User (Tclass_86* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_87 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_87 {
public:
    Cclass_87 () = default;
    int func_a () { return 88; }
    int func_b () { return 90; }
};
static_assert(Iclass_87<Cclass_87>);
template <Iclass_87 Tclass_87>
class Cclass_87_User {
private:
    Tclass_87* m_class { nullptr };
public:
    Cclass_87_User (Tclass_87* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_88 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_88 {
public:
    Cclass_88 () = default;
    int func_a () { return 89; }
    int func_b () { return 91; }
};
static_assert(Iclass_88<Cclass_88>);
template <Iclass_88 Tclass_88>
class Cclass_88_User {
private:
    Tclass_88* m_class { nullptr };
public:
    Cclass_88_User (Tclass_88* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_89 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_89 {
public:
    Cclass_89 () = default;
    int func_a () { return 90; }
    int func_b () { return 92; }
};
static_assert(Iclass_89<Cclass_89>);
template <Iclass_89 Tclass_89>
class Cclass_89_User {
private:
    Tclass_89* m_class { nullptr };
public:
    Cclass_89_User (Tclass_89* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_90 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_90 {
public:
    Cclass_90 () = default;
    int func_a () { return 91; }
    int func_b () { return 93; }
};
static_assert(Iclass_90<Cclass_90>);
template <Iclass_90 Tclass_90>
class Cclass_90_User {
private:
    Tclass_90* m_class { nullptr };
public:
    Cclass_90_User (Tclass_90* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_91 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_91 {
public:
    Cclass_91 () = default;
    int func_a () { return 92; }
    int func_b () { return 94; }
};
static_assert(Iclass_91<Cclass_91>);
template <Iclass_91 Tclass_91>
class Cclass_91_User {
private:
    Tclass_91* m_class { nullptr };
public:
    Cclass_91_User (Tclass_91* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_92 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_92 {
public:
    Cclass_92 () = default;
    int func_a () { return 93; }
    int func_b () { return 95; }
};
static_assert(Iclass_92<Cclass_92>);
template <Iclass_92 Tclass_92>
class Cclass_92_User {
private:
    Tclass_92* m_class { nullptr };
public:
    Cclass_92_User (Tclass_92* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_93 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_93 {
public:
    Cclass_93 () = default;
    int func_a () { return 94; }
    int func_b () { return 96; }
};
static_assert(Iclass_93<Cclass_93>);
template <Iclass_93 Tclass_93>
class Cclass_93_User {
private:
    Tclass_93* m_class { nullptr };
public:
    Cclass_93_User (Tclass_93* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_94 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_94 {
public:
    Cclass_94 () = default;
    int func_a () { return 95; }
    int func_b () { return 97; }
};
static_assert(Iclass_94<Cclass_94>);
template <Iclass_94 Tclass_94>
class Cclass_94_User {
private:
    Tclass_94* m_class { nullptr };
public:
    Cclass_94_User (Tclass_94* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_95 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_95 {
public:
    Cclass_95 () = default;
    int func_a () { return 96; }
    int func_b () { return 98; }
};
static_assert(Iclass_95<Cclass_95>);
template <Iclass_95 Tclass_95>
class Cclass_95_User {
private:
    Tclass_95* m_class { nullptr };
public:
    Cclass_95_User (Tclass_95* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_96 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_96 {
public:
    Cclass_96 () = default;
    int func_a () { return 97; }
    int func_b () { return 99; }
};
static_assert(Iclass_96<Cclass_96>);
template <Iclass_96 Tclass_96>
class Cclass_96_User {
private:
    Tclass_96* m_class { nullptr };
public:
    Cclass_96_User (Tclass_96* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_97 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_97 {
public:
    Cclass_97 () = default;
    int func_a () { return 98; }
    int func_b () { return 100; }
};
static_assert(Iclass_97<Cclass_97>);
template <Iclass_97 Tclass_97>
class Cclass_97_User {
private:
    Tclass_97* m_class { nullptr };
public:
    Cclass_97_User (Tclass_97* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_98 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_98 {
public:
    Cclass_98 () = default;
    int func_a () { return 99; }
    int func_b () { return 101; }
};
static_assert(Iclass_98<Cclass_98>);
template <Iclass_98 Tclass_98>
class Cclass_98_User {
private:
    Tclass_98* m_class { nullptr };
public:
    Cclass_98_User (Tclass_98* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_99 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_99 {
public:
    Cclass_99 () = default;
    int func_a () { return 100; }
    int func_b () { return 102; }
};
static_assert(Iclass_99<Cclass_99>);
template <Iclass_99 Tclass_99>
class Cclass_99_User {
private:
    Tclass_99* m_class { nullptr };
public:
    Cclass_99_User (Tclass_99* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_100 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_100 {
public:
    Cclass_100 () = default;
    int func_a () { return 101; }
    int func_b () { return 103; }
};
static_assert(Iclass_100<Cclass_100>);
template <Iclass_100 Tclass_100>
class Cclass_100_User {
private:
    Tclass_100* m_class { nullptr };
public:
    Cclass_100_User (Tclass_100* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_101 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_101 {
public:
    Cclass_101 () = default;
    int func_a () { return 102; }
    int func_b () { return 104; }
};
static_assert(Iclass_101<Cclass_101>);
template <Iclass_101 Tclass_101>
class Cclass_101_User {
private:
    Tclass_101* m_class { nullptr };
public:
    Cclass_101_User (Tclass_101* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_102 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_102 {
public:
    Cclass_102 () = default;
    int func_a () { return 103; }
    int func_b () { return 105; }
};
static_assert(Iclass_102<Cclass_102>);
template <Iclass_102 Tclass_102>
class Cclass_102_User {
private:
    Tclass_102* m_class { nullptr };
public:
    Cclass_102_User (Tclass_102* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_103 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_103 {
public:
    Cclass_103 () = default;
    int func_a () { return 104; }
    int func_b () { return 106; }
};
static_assert(Iclass_103<Cclass_103>);
template <Iclass_103 Tclass_103>
class Cclass_103_User {
private:
    Tclass_103* m_class { nullptr };
public:
    Cclass_103_User (Tclass_103* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_104 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_104 {
public:
    Cclass_104 () = default;
    int func_a () { return 105; }
    int func_b () { return 107; }
};
static_assert(Iclass_104<Cclass_104>);
template <Iclass_104 Tclass_104>
class Cclass_104_User {
private:
    Tclass_104* m_class { nullptr };
public:
    Cclass_104_User (Tclass_104* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_105 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_105 {
public:
    Cclass_105 () = default;
    int func_a () { return 106; }
    int func_b () { return 108; }
};
static_assert(Iclass_105<Cclass_105>);
template <Iclass_105 Tclass_105>
class Cclass_105_User {
private:
    Tclass_105* m_class { nullptr };
public:
    Cclass_105_User (Tclass_105* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_106 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_106 {
public:
    Cclass_106 () = default;
    int func_a () { return 107; }
    int func_b () { return 109; }
};
static_assert(Iclass_106<Cclass_106>);
template <Iclass_106 Tclass_106>
class Cclass_106_User {
private:
    Tclass_106* m_class { nullptr };
public:
    Cclass_106_User (Tclass_106* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_107 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_107 {
public:
    Cclass_107 () = default;
    int func_a () { return 108; }
    int func_b () { return 110; }
};
static_assert(Iclass_107<Cclass_107>);
template <Iclass_107 Tclass_107>
class Cclass_107_User {
private:
    Tclass_107* m_class { nullptr };
public:
    Cclass_107_User (Tclass_107* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_108 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_108 {
public:
    Cclass_108 () = default;
    int func_a () { return 109; }
    int func_b () { return 111; }
};
static_assert(Iclass_108<Cclass_108>);
template <Iclass_108 Tclass_108>
class Cclass_108_User {
private:
    Tclass_108* m_class { nullptr };
public:
    Cclass_108_User (Tclass_108* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_109 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_109 {
public:
    Cclass_109 () = default;
    int func_a () { return 110; }
    int func_b () { return 112; }
};
static_assert(Iclass_109<Cclass_109>);
template <Iclass_109 Tclass_109>
class Cclass_109_User {
private:
    Tclass_109* m_class { nullptr };
public:
    Cclass_109_User (Tclass_109* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_110 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_110 {
public:
    Cclass_110 () = default;
    int func_a () { return 111; }
    int func_b () { return 113; }
};
static_assert(Iclass_110<Cclass_110>);
template <Iclass_110 Tclass_110>
class Cclass_110_User {
private:
    Tclass_110* m_class { nullptr };
public:
    Cclass_110_User (Tclass_110* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_111 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_111 {
public:
    Cclass_111 () = default;
    int func_a () { return 112; }
    int func_b () { return 114; }
};
static_assert(Iclass_111<Cclass_111>);
template <Iclass_111 Tclass_111>
class Cclass_111_User {
private:
    Tclass_111* m_class { nullptr };
public:
    Cclass_111_User (Tclass_111* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_112 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_112 {
public:
    Cclass_112 () = default;
    int func_a () { return 113; }
    int func_b () { return 115; }
};
static_assert(Iclass_112<Cclass_112>);
template <Iclass_112 Tclass_112>
class Cclass_112_User {
private:
    Tclass_112* m_class { nullptr };
public:
    Cclass_112_User (Tclass_112* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_113 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_113 {
public:
    Cclass_113 () = default;
    int func_a () { return 114; }
    int func_b () { return 116; }
};
static_assert(Iclass_113<Cclass_113>);
template <Iclass_113 Tclass_113>
class Cclass_113_User {
private:
    Tclass_113* m_class { nullptr };
public:
    Cclass_113_User (Tclass_113* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_114 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_114 {
public:
    Cclass_114 () = default;
    int func_a () { return 115; }
    int func_b () { return 117; }
};
static_assert(Iclass_114<Cclass_114>);
template <Iclass_114 Tclass_114>
class Cclass_114_User {
private:
    Tclass_114* m_class { nullptr };
public:
    Cclass_114_User (Tclass_114* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_115 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_115 {
public:
    Cclass_115 () = default;
    int func_a () { return 116; }
    int func_b () { return 118; }
};
static_assert(Iclass_115<Cclass_115>);
template <Iclass_115 Tclass_115>
class Cclass_115_User {
private:
    Tclass_115* m_class { nullptr };
public:
    Cclass_115_User (Tclass_115* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_116 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_116 {
public:
    Cclass_116 () = default;
    int func_a () { return 117; }
    int func_b () { return 119; }
};
static_assert(Iclass_116<Cclass_116>);
template <Iclass_116 Tclass_116>
class Cclass_116_User {
private:
    Tclass_116* m_class { nullptr };
public:
    Cclass_116_User (Tclass_116* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_117 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_117 {
public:
    Cclass_117 () = default;
    int func_a () { return 118; }
    int func_b () { return 120; }
};
static_assert(Iclass_117<Cclass_117>);
template <Iclass_117 Tclass_117>
class Cclass_117_User {
private:
    Tclass_117* m_class { nullptr };
public:
    Cclass_117_User (Tclass_117* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_118 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_118 {
public:
    Cclass_118 () = default;
    int func_a () { return 119; }
    int func_b () { return 121; }
};
static_assert(Iclass_118<Cclass_118>);
template <Iclass_118 Tclass_118>
class Cclass_118_User {
private:
    Tclass_118* m_class { nullptr };
public:
    Cclass_118_User (Tclass_118* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_119 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_119 {
public:
    Cclass_119 () = default;
    int func_a () { return 120; }
    int func_b () { return 122; }
};
static_assert(Iclass_119<Cclass_119>);
template <Iclass_119 Tclass_119>
class Cclass_119_User {
private:
    Tclass_119* m_class { nullptr };
public:
    Cclass_119_User (Tclass_119* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_120 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_120 {
public:
    Cclass_120 () = default;
    int func_a () { return 121; }
    int func_b () { return 123; }
};
static_assert(Iclass_120<Cclass_120>);
template <Iclass_120 Tclass_120>
class Cclass_120_User {
private:
    Tclass_120* m_class { nullptr };
public:
    Cclass_120_User (Tclass_120* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_121 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_121 {
public:
    Cclass_121 () = default;
    int func_a () { return 122; }
    int func_b () { return 124; }
};
static_assert(Iclass_121<Cclass_121>);
template <Iclass_121 Tclass_121>
class Cclass_121_User {
private:
    Tclass_121* m_class { nullptr };
public:
    Cclass_121_User (Tclass_121* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_122 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_122 {
public:
    Cclass_122 () = default;
    int func_a () { return 123; }
    int func_b () { return 125; }
};
static_assert(Iclass_122<Cclass_122>);
template <Iclass_122 Tclass_122>
class Cclass_122_User {
private:
    Tclass_122* m_class { nullptr };
public:
    Cclass_122_User (Tclass_122* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_123 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_123 {
public:
    Cclass_123 () = default;
    int func_a () { return 124; }
    int func_b () { return 126; }
};
static_assert(Iclass_123<Cclass_123>);
template <Iclass_123 Tclass_123>
class Cclass_123_User {
private:
    Tclass_123* m_class { nullptr };
public:
    Cclass_123_User (Tclass_123* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_124 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_124 {
public:
    Cclass_124 () = default;
    int func_a () { return 125; }
    int func_b () { return 127; }
};
static_assert(Iclass_124<Cclass_124>);
template <Iclass_124 Tclass_124>
class Cclass_124_User {
private:
    Tclass_124* m_class { nullptr };
public:
    Cclass_124_User (Tclass_124* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_125 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_125 {
public:
    Cclass_125 () = default;
    int func_a () { return 126; }
    int func_b () { return 128; }
};
static_assert(Iclass_125<Cclass_125>);
template <Iclass_125 Tclass_125>
class Cclass_125_User {
private:
    Tclass_125* m_class { nullptr };
public:
    Cclass_125_User (Tclass_125* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_126 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_126 {
public:
    Cclass_126 () = default;
    int func_a () { return 127; }
    int func_b () { return 129; }
};
static_assert(Iclass_126<Cclass_126>);
template <Iclass_126 Tclass_126>
class Cclass_126_User {
private:
    Tclass_126* m_class { nullptr };
public:
    Cclass_126_User (Tclass_126* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_127 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_127 {
public:
    Cclass_127 () = default;
    int func_a () { return 128; }
    int func_b () { return 130; }
};
static_assert(Iclass_127<Cclass_127>);
template <Iclass_127 Tclass_127>
class Cclass_127_User {
private:
    Tclass_127* m_class { nullptr };
public:
    Cclass_127_User (Tclass_127* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_128 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_128 {
public:
    Cclass_128 () = default;
    int func_a () { return 129; }
    int func_b () { return 131; }
};
static_assert(Iclass_128<Cclass_128>);
template <Iclass_128 Tclass_128>
class Cclass_128_User {
private:
    Tclass_128* m_class { nullptr };
public:
    Cclass_128_User (Tclass_128* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_129 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_129 {
public:
    Cclass_129 () = default;
    int func_a () { return 130; }
    int func_b () { return 132; }
};
static_assert(Iclass_129<Cclass_129>);
template <Iclass_129 Tclass_129>
class Cclass_129_User {
private:
    Tclass_129* m_class { nullptr };
public:
    Cclass_129_User (Tclass_129* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_130 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_130 {
public:
    Cclass_130 () = default;
    int func_a () { return 131; }
    int func_b () { return 133; }
};
static_assert(Iclass_130<Cclass_130>);
template <Iclass_130 Tclass_130>
class Cclass_130_User {
private:
    Tclass_130* m_class { nullptr };
public:
    Cclass_130_User (Tclass_130* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_131 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_131 {
public:
    Cclass_131 () = default;
    int func_a () { return 132; }
    int func_b () { return 134; }
};
static_assert(Iclass_131<Cclass_131>);
template <Iclass_131 Tclass_131>
class Cclass_131_User {
private:
    Tclass_131* m_class { nullptr };
public:
    Cclass_131_User (Tclass_131* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_132 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_132 {
public:
    Cclass_132 () = default;
    int func_a () { return 133; }
    int func_b () { return 135; }
};
static_assert(Iclass_132<Cclass_132>);
template <Iclass_132 Tclass_132>
class Cclass_132_User {
private:
    Tclass_132* m_class { nullptr };
public:
    Cclass_132_User (Tclass_132* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_133 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_133 {
public:
    Cclass_133 () = default;
    int func_a () { return 134; }
    int func_b () { return 136; }
};
static_assert(Iclass_133<Cclass_133>);
template <Iclass_133 Tclass_133>
class Cclass_133_User {
private:
    Tclass_133* m_class { nullptr };
public:
    Cclass_133_User (Tclass_133* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_134 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_134 {
public:
    Cclass_134 () = default;
    int func_a () { return 135; }
    int func_b () { return 137; }
};
static_assert(Iclass_134<Cclass_134>);
template <Iclass_134 Tclass_134>
class Cclass_134_User {
private:
    Tclass_134* m_class { nullptr };
public:
    Cclass_134_User (Tclass_134* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_135 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_135 {
public:
    Cclass_135 () = default;
    int func_a () { return 136; }
    int func_b () { return 138; }
};
static_assert(Iclass_135<Cclass_135>);
template <Iclass_135 Tclass_135>
class Cclass_135_User {
private:
    Tclass_135* m_class { nullptr };
public:
    Cclass_135_User (Tclass_135* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_136 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_136 {
public:
    Cclass_136 () = default;
    int func_a () { return 137; }
    int func_b () { return 139; }
};
static_assert(Iclass_136<Cclass_136>);
template <Iclass_136 Tclass_136>
class Cclass_136_User {
private:
    Tclass_136* m_class { nullptr };
public:
    Cclass_136_User (Tclass_136* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_137 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_137 {
public:
    Cclass_137 () = default;
    int func_a () { return 138; }
    int func_b () { return 140; }
};
static_assert(Iclass_137<Cclass_137>);
template <Iclass_137 Tclass_137>
class Cclass_137_User {
private:
    Tclass_137* m_class { nullptr };
public:
    Cclass_137_User (Tclass_137* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_138 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_138 {
public:
    Cclass_138 () = default;
    int func_a () { return 139; }
    int func_b () { return 141; }
};
static_assert(Iclass_138<Cclass_138>);
template <Iclass_138 Tclass_138>
class Cclass_138_User {
private:
    Tclass_138* m_class { nullptr };
public:
    Cclass_138_User (Tclass_138* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_139 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_139 {
public:
    Cclass_139 () = default;
    int func_a () { return 140; }
    int func_b () { return 142; }
};
static_assert(Iclass_139<Cclass_139>);
template <Iclass_139 Tclass_139>
class Cclass_139_User {
private:
    Tclass_139* m_class { nullptr };
public:
    Cclass_139_User (Tclass_139* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_140 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_140 {
public:
    Cclass_140 () = default;
    int func_a () { return 141; }
    int func_b () { return 143; }
};
static_assert(Iclass_140<Cclass_140>);
template <Iclass_140 Tclass_140>
class Cclass_140_User {
private:
    Tclass_140* m_class { nullptr };
public:
    Cclass_140_User (Tclass_140* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_141 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_141 {
public:
    Cclass_141 () = default;
    int func_a () { return 142; }
    int func_b () { return 144; }
};
static_assert(Iclass_141<Cclass_141>);
template <Iclass_141 Tclass_141>
class Cclass_141_User {
private:
    Tclass_141* m_class { nullptr };
public:
    Cclass_141_User (Tclass_141* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_142 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_142 {
public:
    Cclass_142 () = default;
    int func_a () { return 143; }
    int func_b () { return 145; }
};
static_assert(Iclass_142<Cclass_142>);
template <Iclass_142 Tclass_142>
class Cclass_142_User {
private:
    Tclass_142* m_class { nullptr };
public:
    Cclass_142_User (Tclass_142* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_143 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_143 {
public:
    Cclass_143 () = default;
    int func_a () { return 144; }
    int func_b () { return 146; }
};
static_assert(Iclass_143<Cclass_143>);
template <Iclass_143 Tclass_143>
class Cclass_143_User {
private:
    Tclass_143* m_class { nullptr };
public:
    Cclass_143_User (Tclass_143* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_144 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_144 {
public:
    Cclass_144 () = default;
    int func_a () { return 145; }
    int func_b () { return 147; }
};
static_assert(Iclass_144<Cclass_144>);
template <Iclass_144 Tclass_144>
class Cclass_144_User {
private:
    Tclass_144* m_class { nullptr };
public:
    Cclass_144_User (Tclass_144* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_145 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_145 {
public:
    Cclass_145 () = default;
    int func_a () { return 146; }
    int func_b () { return 148; }
};
static_assert(Iclass_145<Cclass_145>);
template <Iclass_145 Tclass_145>
class Cclass_145_User {
private:
    Tclass_145* m_class { nullptr };
public:
    Cclass_145_User (Tclass_145* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_146 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_146 {
public:
    Cclass_146 () = default;
    int func_a () { return 147; }
    int func_b () { return 149; }
};
static_assert(Iclass_146<Cclass_146>);
template <Iclass_146 Tclass_146>
class Cclass_146_User {
private:
    Tclass_146* m_class { nullptr };
public:
    Cclass_146_User (Tclass_146* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_147 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_147 {
public:
    Cclass_147 () = default;
    int func_a () { return 148; }
    int func_b () { return 150; }
};
static_assert(Iclass_147<Cclass_147>);
template <Iclass_147 Tclass_147>
class Cclass_147_User {
private:
    Tclass_147* m_class { nullptr };
public:
    Cclass_147_User (Tclass_147* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_148 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_148 {
public:
    Cclass_148 () = default;
    int func_a () { return 149; }
    int func_b () { return 151; }
};
static_assert(Iclass_148<Cclass_148>);
template <Iclass_148 Tclass_148>
class Cclass_148_User {
private:
    Tclass_148* m_class { nullptr };
public:
    Cclass_148_User (Tclass_148* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_149 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_149 {
public:
    Cclass_149 () = default;
    int func_a () { return 150; }
    int func_b () { return 152; }
};
static_assert(Iclass_149<Cclass_149>);
template <Iclass_149 Tclass_149>
class Cclass_149_User {
private:
    Tclass_149* m_class { nullptr };
public:
    Cclass_149_User (Tclass_149* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_150 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_150 {
public:
    Cclass_150 () = default;
    int func_a () { return 151; }
    int func_b () { return 153; }
};
static_assert(Iclass_150<Cclass_150>);
template <Iclass_150 Tclass_150>
class Cclass_150_User {
private:
    Tclass_150* m_class { nullptr };
public:
    Cclass_150_User (Tclass_150* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_151 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_151 {
public:
    Cclass_151 () = default;
    int func_a () { return 152; }
    int func_b () { return 154; }
};
static_assert(Iclass_151<Cclass_151>);
template <Iclass_151 Tclass_151>
class Cclass_151_User {
private:
    Tclass_151* m_class { nullptr };
public:
    Cclass_151_User (Tclass_151* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_152 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_152 {
public:
    Cclass_152 () = default;
    int func_a () { return 153; }
    int func_b () { return 155; }
};
static_assert(Iclass_152<Cclass_152>);
template <Iclass_152 Tclass_152>
class Cclass_152_User {
private:
    Tclass_152* m_class { nullptr };
public:
    Cclass_152_User (Tclass_152* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_153 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_153 {
public:
    Cclass_153 () = default;
    int func_a () { return 154; }
    int func_b () { return 156; }
};
static_assert(Iclass_153<Cclass_153>);
template <Iclass_153 Tclass_153>
class Cclass_153_User {
private:
    Tclass_153* m_class { nullptr };
public:
    Cclass_153_User (Tclass_153* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_154 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_154 {
public:
    Cclass_154 () = default;
    int func_a () { return 155; }
    int func_b () { return 157; }
};
static_assert(Iclass_154<Cclass_154>);
template <Iclass_154 Tclass_154>
class Cclass_154_User {
private:
    Tclass_154* m_class { nullptr };
public:
    Cclass_154_User (Tclass_154* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_155 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_155 {
public:
    Cclass_155 () = default;
    int func_a () { return 156; }
    int func_b () { return 158; }
};
static_assert(Iclass_155<Cclass_155>);
template <Iclass_155 Tclass_155>
class Cclass_155_User {
private:
    Tclass_155* m_class { nullptr };
public:
    Cclass_155_User (Tclass_155* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_156 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_156 {
public:
    Cclass_156 () = default;
    int func_a () { return 157; }
    int func_b () { return 159; }
};
static_assert(Iclass_156<Cclass_156>);
template <Iclass_156 Tclass_156>
class Cclass_156_User {
private:
    Tclass_156* m_class { nullptr };
public:
    Cclass_156_User (Tclass_156* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_157 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_157 {
public:
    Cclass_157 () = default;
    int func_a () { return 158; }
    int func_b () { return 160; }
};
static_assert(Iclass_157<Cclass_157>);
template <Iclass_157 Tclass_157>
class Cclass_157_User {
private:
    Tclass_157* m_class { nullptr };
public:
    Cclass_157_User (Tclass_157* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_158 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_158 {
public:
    Cclass_158 () = default;
    int func_a () { return 159; }
    int func_b () { return 161; }
};
static_assert(Iclass_158<Cclass_158>);
template <Iclass_158 Tclass_158>
class Cclass_158_User {
private:
    Tclass_158* m_class { nullptr };
public:
    Cclass_158_User (Tclass_158* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_159 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_159 {
public:
    Cclass_159 () = default;
    int func_a () { return 160; }
    int func_b () { return 162; }
};
static_assert(Iclass_159<Cclass_159>);
template <Iclass_159 Tclass_159>
class Cclass_159_User {
private:
    Tclass_159* m_class { nullptr };
public:
    Cclass_159_User (Tclass_159* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_160 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_160 {
public:
    Cclass_160 () = default;
    int func_a () { return 161; }
    int func_b () { return 163; }
};
static_assert(Iclass_160<Cclass_160>);
template <Iclass_160 Tclass_160>
class Cclass_160_User {
private:
    Tclass_160* m_class { nullptr };
public:
    Cclass_160_User (Tclass_160* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_161 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_161 {
public:
    Cclass_161 () = default;
    int func_a () { return 162; }
    int func_b () { return 164; }
};
static_assert(Iclass_161<Cclass_161>);
template <Iclass_161 Tclass_161>
class Cclass_161_User {
private:
    Tclass_161* m_class { nullptr };
public:
    Cclass_161_User (Tclass_161* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_162 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_162 {
public:
    Cclass_162 () = default;
    int func_a () { return 163; }
    int func_b () { return 165; }
};
static_assert(Iclass_162<Cclass_162>);
template <Iclass_162 Tclass_162>
class Cclass_162_User {
private:
    Tclass_162* m_class { nullptr };
public:
    Cclass_162_User (Tclass_162* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_163 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_163 {
public:
    Cclass_163 () = default;
    int func_a () { return 164; }
    int func_b () { return 166; }
};
static_assert(Iclass_163<Cclass_163>);
template <Iclass_163 Tclass_163>
class Cclass_163_User {
private:
    Tclass_163* m_class { nullptr };
public:
    Cclass_163_User (Tclass_163* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_164 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_164 {
public:
    Cclass_164 () = default;
    int func_a () { return 165; }
    int func_b () { return 167; }
};
static_assert(Iclass_164<Cclass_164>);
template <Iclass_164 Tclass_164>
class Cclass_164_User {
private:
    Tclass_164* m_class { nullptr };
public:
    Cclass_164_User (Tclass_164* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_165 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_165 {
public:
    Cclass_165 () = default;
    int func_a () { return 166; }
    int func_b () { return 168; }
};
static_assert(Iclass_165<Cclass_165>);
template <Iclass_165 Tclass_165>
class Cclass_165_User {
private:
    Tclass_165* m_class { nullptr };
public:
    Cclass_165_User (Tclass_165* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_166 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_166 {
public:
    Cclass_166 () = default;
    int func_a () { return 167; }
    int func_b () { return 169; }
};
static_assert(Iclass_166<Cclass_166>);
template <Iclass_166 Tclass_166>
class Cclass_166_User {
private:
    Tclass_166* m_class { nullptr };
public:
    Cclass_166_User (Tclass_166* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_167 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_167 {
public:
    Cclass_167 () = default;
    int func_a () { return 168; }
    int func_b () { return 170; }
};
static_assert(Iclass_167<Cclass_167>);
template <Iclass_167 Tclass_167>
class Cclass_167_User {
private:
    Tclass_167* m_class { nullptr };
public:
    Cclass_167_User (Tclass_167* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_168 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_168 {
public:
    Cclass_168 () = default;
    int func_a () { return 169; }
    int func_b () { return 171; }
};
static_assert(Iclass_168<Cclass_168>);
template <Iclass_168 Tclass_168>
class Cclass_168_User {
private:
    Tclass_168* m_class { nullptr };
public:
    Cclass_168_User (Tclass_168* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_169 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_169 {
public:
    Cclass_169 () = default;
    int func_a () { return 170; }
    int func_b () { return 172; }
};
static_assert(Iclass_169<Cclass_169>);
template <Iclass_169 Tclass_169>
class Cclass_169_User {
private:
    Tclass_169* m_class { nullptr };
public:
    Cclass_169_User (Tclass_169* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_170 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_170 {
public:
    Cclass_170 () = default;
    int func_a () { return 171; }
    int func_b () { return 173; }
};
static_assert(Iclass_170<Cclass_170>);
template <Iclass_170 Tclass_170>
class Cclass_170_User {
private:
    Tclass_170* m_class { nullptr };
public:
    Cclass_170_User (Tclass_170* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_171 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_171 {
public:
    Cclass_171 () = default;
    int func_a () { return 172; }
    int func_b () { return 174; }
};
static_assert(Iclass_171<Cclass_171>);
template <Iclass_171 Tclass_171>
class Cclass_171_User {
private:
    Tclass_171* m_class { nullptr };
public:
    Cclass_171_User (Tclass_171* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_172 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_172 {
public:
    Cclass_172 () = default;
    int func_a () { return 173; }
    int func_b () { return 175; }
};
static_assert(Iclass_172<Cclass_172>);
template <Iclass_172 Tclass_172>
class Cclass_172_User {
private:
    Tclass_172* m_class { nullptr };
public:
    Cclass_172_User (Tclass_172* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_173 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_173 {
public:
    Cclass_173 () = default;
    int func_a () { return 174; }
    int func_b () { return 176; }
};
static_assert(Iclass_173<Cclass_173>);
template <Iclass_173 Tclass_173>
class Cclass_173_User {
private:
    Tclass_173* m_class { nullptr };
public:
    Cclass_173_User (Tclass_173* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_174 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_174 {
public:
    Cclass_174 () = default;
    int func_a () { return 175; }
    int func_b () { return 177; }
};
static_assert(Iclass_174<Cclass_174>);
template <Iclass_174 Tclass_174>
class Cclass_174_User {
private:
    Tclass_174* m_class { nullptr };
public:
    Cclass_174_User (Tclass_174* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_175 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_175 {
public:
    Cclass_175 () = default;
    int func_a () { return 176; }
    int func_b () { return 178; }
};
static_assert(Iclass_175<Cclass_175>);
template <Iclass_175 Tclass_175>
class Cclass_175_User {
private:
    Tclass_175* m_class { nullptr };
public:
    Cclass_175_User (Tclass_175* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_176 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_176 {
public:
    Cclass_176 () = default;
    int func_a () { return 177; }
    int func_b () { return 179; }
};
static_assert(Iclass_176<Cclass_176>);
template <Iclass_176 Tclass_176>
class Cclass_176_User {
private:
    Tclass_176* m_class { nullptr };
public:
    Cclass_176_User (Tclass_176* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_177 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_177 {
public:
    Cclass_177 () = default;
    int func_a () { return 178; }
    int func_b () { return 180; }
};
static_assert(Iclass_177<Cclass_177>);
template <Iclass_177 Tclass_177>
class Cclass_177_User {
private:
    Tclass_177* m_class { nullptr };
public:
    Cclass_177_User (Tclass_177* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_178 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_178 {
public:
    Cclass_178 () = default;
    int func_a () { return 179; }
    int func_b () { return 181; }
};
static_assert(Iclass_178<Cclass_178>);
template <Iclass_178 Tclass_178>
class Cclass_178_User {
private:
    Tclass_178* m_class { nullptr };
public:
    Cclass_178_User (Tclass_178* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_179 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_179 {
public:
    Cclass_179 () = default;
    int func_a () { return 180; }
    int func_b () { return 182; }
};
static_assert(Iclass_179<Cclass_179>);
template <Iclass_179 Tclass_179>
class Cclass_179_User {
private:
    Tclass_179* m_class { nullptr };
public:
    Cclass_179_User (Tclass_179* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_180 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_180 {
public:
    Cclass_180 () = default;
    int func_a () { return 181; }
    int func_b () { return 183; }
};
static_assert(Iclass_180<Cclass_180>);
template <Iclass_180 Tclass_180>
class Cclass_180_User {
private:
    Tclass_180* m_class { nullptr };
public:
    Cclass_180_User (Tclass_180* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_181 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_181 {
public:
    Cclass_181 () = default;
    int func_a () { return 182; }
    int func_b () { return 184; }
};
static_assert(Iclass_181<Cclass_181>);
template <Iclass_181 Tclass_181>
class Cclass_181_User {
private:
    Tclass_181* m_class { nullptr };
public:
    Cclass_181_User (Tclass_181* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_182 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_182 {
public:
    Cclass_182 () = default;
    int func_a () { return 183; }
    int func_b () { return 185; }
};
static_assert(Iclass_182<Cclass_182>);
template <Iclass_182 Tclass_182>
class Cclass_182_User {
private:
    Tclass_182* m_class { nullptr };
public:
    Cclass_182_User (Tclass_182* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_183 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_183 {
public:
    Cclass_183 () = default;
    int func_a () { return 184; }
    int func_b () { return 186; }
};
static_assert(Iclass_183<Cclass_183>);
template <Iclass_183 Tclass_183>
class Cclass_183_User {
private:
    Tclass_183* m_class { nullptr };
public:
    Cclass_183_User (Tclass_183* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_184 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_184 {
public:
    Cclass_184 () = default;
    int func_a () { return 185; }
    int func_b () { return 187; }
};
static_assert(Iclass_184<Cclass_184>);
template <Iclass_184 Tclass_184>
class Cclass_184_User {
private:
    Tclass_184* m_class { nullptr };
public:
    Cclass_184_User (Tclass_184* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_185 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_185 {
public:
    Cclass_185 () = default;
    int func_a () { return 186; }
    int func_b () { return 188; }
};
static_assert(Iclass_185<Cclass_185>);
template <Iclass_185 Tclass_185>
class Cclass_185_User {
private:
    Tclass_185* m_class { nullptr };
public:
    Cclass_185_User (Tclass_185* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_186 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_186 {
public:
    Cclass_186 () = default;
    int func_a () { return 187; }
    int func_b () { return 189; }
};
static_assert(Iclass_186<Cclass_186>);
template <Iclass_186 Tclass_186>
class Cclass_186_User {
private:
    Tclass_186* m_class { nullptr };
public:
    Cclass_186_User (Tclass_186* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_187 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_187 {
public:
    Cclass_187 () = default;
    int func_a () { return 188; }
    int func_b () { return 190; }
};
static_assert(Iclass_187<Cclass_187>);
template <Iclass_187 Tclass_187>
class Cclass_187_User {
private:
    Tclass_187* m_class { nullptr };
public:
    Cclass_187_User (Tclass_187* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_188 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_188 {
public:
    Cclass_188 () = default;
    int func_a () { return 189; }
    int func_b () { return 191; }
};
static_assert(Iclass_188<Cclass_188>);
template <Iclass_188 Tclass_188>
class Cclass_188_User {
private:
    Tclass_188* m_class { nullptr };
public:
    Cclass_188_User (Tclass_188* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_189 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_189 {
public:
    Cclass_189 () = default;
    int func_a () { return 190; }
    int func_b () { return 192; }
};
static_assert(Iclass_189<Cclass_189>);
template <Iclass_189 Tclass_189>
class Cclass_189_User {
private:
    Tclass_189* m_class { nullptr };
public:
    Cclass_189_User (Tclass_189* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_190 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_190 {
public:
    Cclass_190 () = default;
    int func_a () { return 191; }
    int func_b () { return 193; }
};
static_assert(Iclass_190<Cclass_190>);
template <Iclass_190 Tclass_190>
class Cclass_190_User {
private:
    Tclass_190* m_class { nullptr };
public:
    Cclass_190_User (Tclass_190* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_191 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_191 {
public:
    Cclass_191 () = default;
    int func_a () { return 192; }
    int func_b () { return 194; }
};
static_assert(Iclass_191<Cclass_191>);
template <Iclass_191 Tclass_191>
class Cclass_191_User {
private:
    Tclass_191* m_class { nullptr };
public:
    Cclass_191_User (Tclass_191* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_192 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_192 {
public:
    Cclass_192 () = default;
    int func_a () { return 193; }
    int func_b () { return 195; }
};
static_assert(Iclass_192<Cclass_192>);
template <Iclass_192 Tclass_192>
class Cclass_192_User {
private:
    Tclass_192* m_class { nullptr };
public:
    Cclass_192_User (Tclass_192* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_193 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_193 {
public:
    Cclass_193 () = default;
    int func_a () { return 194; }
    int func_b () { return 196; }
};
static_assert(Iclass_193<Cclass_193>);
template <Iclass_193 Tclass_193>
class Cclass_193_User {
private:
    Tclass_193* m_class { nullptr };
public:
    Cclass_193_User (Tclass_193* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_194 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_194 {
public:
    Cclass_194 () = default;
    int func_a () { return 195; }
    int func_b () { return 197; }
};
static_assert(Iclass_194<Cclass_194>);
template <Iclass_194 Tclass_194>
class Cclass_194_User {
private:
    Tclass_194* m_class { nullptr };
public:
    Cclass_194_User (Tclass_194* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_195 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_195 {
public:
    Cclass_195 () = default;
    int func_a () { return 196; }
    int func_b () { return 198; }
};
static_assert(Iclass_195<Cclass_195>);
template <Iclass_195 Tclass_195>
class Cclass_195_User {
private:
    Tclass_195* m_class { nullptr };
public:
    Cclass_195_User (Tclass_195* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_196 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_196 {
public:
    Cclass_196 () = default;
    int func_a () { return 197; }
    int func_b () { return 199; }
};
static_assert(Iclass_196<Cclass_196>);
template <Iclass_196 Tclass_196>
class Cclass_196_User {
private:
    Tclass_196* m_class { nullptr };
public:
    Cclass_196_User (Tclass_196* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_197 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_197 {
public:
    Cclass_197 () = default;
    int func_a () { return 198; }
    int func_b () { return 200; }
};
static_assert(Iclass_197<Cclass_197>);
template <Iclass_197 Tclass_197>
class Cclass_197_User {
private:
    Tclass_197* m_class { nullptr };
public:
    Cclass_197_User (Tclass_197* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_198 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_198 {
public:
    Cclass_198 () = default;
    int func_a () { return 199; }
    int func_b () { return 201; }
};
static_assert(Iclass_198<Cclass_198>);
template <Iclass_198 Tclass_198>
class Cclass_198_User {
private:
    Tclass_198* m_class { nullptr };
public:
    Cclass_198_User (Tclass_198* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
template <typename T>
concept Iclass_199 = requires (T impl) {
    { impl.func_a() } -> std::same_as<int>;
    { impl.func_b() } -> std::same_as<int>;
};
class Cclass_199 {
public:
    Cclass_199 () = default;
    int func_a () { return 200; }
    int func_b () { return 202; }
};
static_assert(Iclass_199<Cclass_199>);
template <Iclass_199 Tclass_199>
class Cclass_199_User {
private:
    Tclass_199* m_class { nullptr };
public:
    Cclass_199_User (Tclass_199* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};

int main (void) {
    __attribute__((unused)) ST_0 inst_ST_0 {};
    inst_ST_0.ST_0_member_0 = ENUM_17_VAL_4;
    inst_ST_0.ST_0_member_1 = ENUM_11_VAL_4;
    inst_ST_0.ST_0_member_2 = ENUM_28_VAL_6;
    inst_ST_0.ST_0_member_3 = ENUM_2_VAL_3;
    inst_ST_0.ST_0_member_4 = ENUM_8_VAL_4;
    inst_ST_0.ST_0_member_5 = ENUM_18_VAL_9;
    inst_ST_0.ST_0_member_6 = ENUM_28_VAL_5;
    inst_ST_0.ST_0_member_7 = ENUM_9_VAL_6;
    inst_ST_0.ST_0_member_8 = ENUM_11_VAL_4;
    inst_ST_0.ST_0_member_9 = ENUM_22_VAL_5;
    __attribute__((unused)) ST_1 inst_ST_1 {};
    inst_ST_1.ST_1_member_0 = ENUM_24_VAL_0;
    inst_ST_1.ST_1_member_1 = ENUM_15_VAL_5;
    inst_ST_1.ST_1_member_2 = ENUM_15_VAL_7;
    inst_ST_1.ST_1_member_3 = 98;
    inst_ST_1.ST_1_member_4 = ENUM_26_VAL_9;
    inst_ST_1.ST_1_member_5 = ENUM_28_VAL_9;
    inst_ST_1.ST_1_member_6 = 3;
    inst_ST_1.ST_1_member_7 = ENUM_28_VAL_3;
    inst_ST_1.ST_1_member_8 = ENUM_7_VAL_7;
    inst_ST_1.ST_1_member_9 = 73;
    __attribute__((unused)) ST_2 inst_ST_2 {};
    inst_ST_2.ST_2_member_0 = ENUM_18_VAL_4;
    inst_ST_2.ST_2_member_1 = ENUM_8_VAL_5;
    inst_ST_2.ST_2_member_2 = ENUM_0_VAL_8;
    inst_ST_2.ST_2_member_3 = ENUM_27_VAL_0;
    inst_ST_2.ST_2_member_4 = ENUM_11_VAL_3;
    inst_ST_2.ST_2_member_5 = ENUM_23_VAL_1;
    inst_ST_2.ST_2_member_6 = ENUM_21_VAL_5;
    inst_ST_2.ST_2_member_7 = ENUM_16_VAL_0;
    inst_ST_2.ST_2_member_8 = ENUM_8_VAL_3;
    inst_ST_2.ST_2_member_9 = ENUM_18_VAL_5;
    __attribute__((unused)) ST_3 inst_ST_3 {};
    inst_ST_3.ST_3_member_0 = ENUM_8_VAL_6;
    inst_ST_3.ST_3_member_1 = ENUM_2_VAL_6;
    inst_ST_3.ST_3_member_2 = 91;
    inst_ST_3.ST_3_member_3 = ENUM_12_VAL_7;
    inst_ST_3.ST_3_member_4 = ENUM_3_VAL_1;
    inst_ST_3.ST_3_member_5 = 36;
    inst_ST_3.ST_3_member_6 = ENUM_28_VAL_9;
    inst_ST_3.ST_3_member_7 = ENUM_16_VAL_1;
    inst_ST_3.ST_3_member_8 = ENUM_17_VAL_6;
    inst_ST_3.ST_3_member_9 = 45;
    __attribute__((unused)) ST_4 inst_ST_4 {};
    inst_ST_4.ST_4_member_0 = ENUM_23_VAL_2;
    inst_ST_4.ST_4_member_1 = ENUM_1_VAL_6;
    inst_ST_4.ST_4_member_2 = ENUM_0_VAL_5;
    inst_ST_4.ST_4_member_3 = ENUM_15_VAL_2;
    inst_ST_4.ST_4_member_4 = ENUM_0_VAL_7;
    inst_ST_4.ST_4_member_5 = ENUM_9_VAL_8;
    inst_ST_4.ST_4_member_6 = 40;
    inst_ST_4.ST_4_member_7 = ENUM_29_VAL_2;
    inst_ST_4.ST_4_member_8 = ENUM_17_VAL_7;
    inst_ST_4.ST_4_member_9 = ENUM_17_VAL_5;
    __attribute__((unused)) ST_5 inst_ST_5 {};
    inst_ST_5.ST_5_member_0 = ENUM_26_VAL_8;
    inst_ST_5.ST_5_member_1 = ENUM_26_VAL_1;
    inst_ST_5.ST_5_member_2 = ENUM_23_VAL_0;
    inst_ST_5.ST_5_member_3 = ENUM_29_VAL_2;
    inst_ST_5.ST_5_member_4 = ENUM_4_VAL_3;
    inst_ST_5.ST_5_member_5 = ENUM_4_VAL_1;
    inst_ST_5.ST_5_member_6 = ENUM_12_VAL_7;
    inst_ST_5.ST_5_member_7 = ENUM_10_VAL_1;
    inst_ST_5.ST_5_member_8 = ENUM_14_VAL_5;
    inst_ST_5.ST_5_member_9 = ENUM_26_VAL_8;
    __attribute__((unused)) ST_6 inst_ST_6 {};
    inst_ST_6.ST_6_member_0 = ENUM_3_VAL_7;
    inst_ST_6.ST_6_member_1 = ENUM_2_VAL_3;
    inst_ST_6.ST_6_member_2 = ENUM_0_VAL_1;
    inst_ST_6.ST_6_member_3 = ENUM_22_VAL_3;
    inst_ST_6.ST_6_member_4 = 36;
    inst_ST_6.ST_6_member_5 = ENUM_9_VAL_3;
    inst_ST_6.ST_6_member_6 = ENUM_5_VAL_8;
    inst_ST_6.ST_6_member_7 = 2;
    inst_ST_6.ST_6_member_8 = ENUM_25_VAL_4;
    inst_ST_6.ST_6_member_9 = ENUM_26_VAL_8;
    __attribute__((unused)) ST_7 inst_ST_7 {};
    inst_ST_7.ST_7_member_0 = ENUM_27_VAL_7;
    inst_ST_7.ST_7_member_1 = ENUM_1_VAL_4;
    inst_ST_7.ST_7_member_2 = ENUM_6_VAL_9;
    inst_ST_7.ST_7_member_3 = ENUM_5_VAL_0;
    inst_ST_7.ST_7_member_4 = ENUM_19_VAL_8;
    inst_ST_7.ST_7_member_5 = ENUM_27_VAL_0;
    inst_ST_7.ST_7_member_6 = ENUM_7_VAL_8;
    inst_ST_7.ST_7_member_7 = ENUM_29_VAL_3;
    inst_ST_7.ST_7_member_8 = 18;
    inst_ST_7.ST_7_member_9 = ENUM_20_VAL_8;
    __attribute__((unused)) ST_8 inst_ST_8 {};
    inst_ST_8.ST_8_member_0 = ENUM_13_VAL_9;
    inst_ST_8.ST_8_member_1 = ENUM_24_VAL_0;
    inst_ST_8.ST_8_member_2 = ENUM_21_VAL_0;
    inst_ST_8.ST_8_member_3 = ENUM_7_VAL_4;
    inst_ST_8.ST_8_member_4 = ENUM_9_VAL_0;
    inst_ST_8.ST_8_member_5 = ENUM_10_VAL_7;
    inst_ST_8.ST_8_member_6 = 65;
    inst_ST_8.ST_8_member_7 = ENUM_8_VAL_6;
    inst_ST_8.ST_8_member_8 = ENUM_22_VAL_2;
    inst_ST_8.ST_8_member_9 = ENUM_21_VAL_4;
    __attribute__((unused)) ST_9 inst_ST_9 {};
    inst_ST_9.ST_9_member_0 = ENUM_7_VAL_4;
    inst_ST_9.ST_9_member_1 = ENUM_26_VAL_3;
    inst_ST_9.ST_9_member_2 = ENUM_4_VAL_5;
    inst_ST_9.ST_9_member_3 = ENUM_22_VAL_0;
    inst_ST_9.ST_9_member_4 = ENUM_19_VAL_5;
    inst_ST_9.ST_9_member_5 = ENUM_10_VAL_6;
    inst_ST_9.ST_9_member_6 = ENUM_10_VAL_6;
    inst_ST_9.ST_9_member_7 = ENUM_26_VAL_1;
    inst_ST_9.ST_9_member_8 = ENUM_18_VAL_6;
    inst_ST_9.ST_9_member_9 = ENUM_23_VAL_6;
    __attribute__((unused)) ST_10 inst_ST_10 {};
    inst_ST_10.ST_10_member_0 = ENUM_17_VAL_2;
    inst_ST_10.ST_10_member_1 = ENUM_2_VAL_8;
    inst_ST_10.ST_10_member_2 = ENUM_3_VAL_9;
    inst_ST_10.ST_10_member_3 = ENUM_1_VAL_4;
    inst_ST_10.ST_10_member_4 = ENUM_22_VAL_0;
    inst_ST_10.ST_10_member_5 = ENUM_19_VAL_4;
    inst_ST_10.ST_10_member_6 = 28;
    inst_ST_10.ST_10_member_7 = ENUM_12_VAL_0;
    inst_ST_10.ST_10_member_8 = ENUM_21_VAL_6;
    inst_ST_10.ST_10_member_9 = ENUM_27_VAL_2;
    __attribute__((unused)) ST_11 inst_ST_11 {};
    inst_ST_11.ST_11_member_0 = ENUM_21_VAL_9;
    inst_ST_11.ST_11_member_1 = ENUM_17_VAL_5;
    inst_ST_11.ST_11_member_2 = ENUM_29_VAL_5;
    inst_ST_11.ST_11_member_3 = ENUM_11_VAL_0;
    inst_ST_11.ST_11_member_4 = ENUM_1_VAL_0;
    inst_ST_11.ST_11_member_5 = ENUM_9_VAL_1;
    inst_ST_11.ST_11_member_6 = ENUM_1_VAL_8;
    inst_ST_11.ST_11_member_7 = ENUM_22_VAL_7;
    inst_ST_11.ST_11_member_8 = ENUM_17_VAL_7;
    inst_ST_11.ST_11_member_9 = ENUM_25_VAL_8;
    __attribute__((unused)) ST_12 inst_ST_12 {};
    inst_ST_12.ST_12_member_0 = ENUM_2_VAL_0;
    inst_ST_12.ST_12_member_1 = ENUM_10_VAL_1;
    inst_ST_12.ST_12_member_2 = ENUM_7_VAL_0;
    inst_ST_12.ST_12_member_3 = ENUM_9_VAL_8;
    inst_ST_12.ST_12_member_4 = ENUM_7_VAL_5;
    inst_ST_12.ST_12_member_5 = ENUM_27_VAL_3;
    inst_ST_12.ST_12_member_6 = ENUM_7_VAL_0;
    inst_ST_12.ST_12_member_7 = ENUM_4_VAL_4;
    inst_ST_12.ST_12_member_8 = ENUM_18_VAL_2;
    inst_ST_12.ST_12_member_9 = ENUM_20_VAL_3;
    __attribute__((unused)) ST_13 inst_ST_13 {};
    inst_ST_13.ST_13_member_0 = ENUM_20_VAL_3;
    inst_ST_13.ST_13_member_1 = ENUM_26_VAL_9;
    inst_ST_13.ST_13_member_2 = ENUM_28_VAL_6;
    inst_ST_13.ST_13_member_3 = 71;
    inst_ST_13.ST_13_member_4 = ENUM_21_VAL_5;
    inst_ST_13.ST_13_member_5 = ENUM_15_VAL_2;
    inst_ST_13.ST_13_member_6 = ENUM_21_VAL_9;
    inst_ST_13.ST_13_member_7 = 9;
    inst_ST_13.ST_13_member_8 = ENUM_23_VAL_0;
    inst_ST_13.ST_13_member_9 = ENUM_20_VAL_4;
    __attribute__((unused)) ST_14 inst_ST_14 {};
    inst_ST_14.ST_14_member_0 = ENUM_16_VAL_2;
    inst_ST_14.ST_14_member_1 = ENUM_14_VAL_1;
    inst_ST_14.ST_14_member_2 = ENUM_26_VAL_5;
    inst_ST_14.ST_14_member_3 = ENUM_27_VAL_9;
    inst_ST_14.ST_14_member_4 = ENUM_16_VAL_3;
    inst_ST_14.ST_14_member_5 = ENUM_13_VAL_3;
    inst_ST_14.ST_14_member_6 = ENUM_12_VAL_8;
    inst_ST_14.ST_14_member_7 = ENUM_4_VAL_7;
    inst_ST_14.ST_14_member_8 = ENUM_10_VAL_8;
    inst_ST_14.ST_14_member_9 = ENUM_22_VAL_6;
    __attribute__((unused)) ST_15 inst_ST_15 {};
    inst_ST_15.ST_15_member_0 = ENUM_14_VAL_9;
    inst_ST_15.ST_15_member_1 = ENUM_0_VAL_3;
    inst_ST_15.ST_15_member_2 = ENUM_18_VAL_2;
    inst_ST_15.ST_15_member_3 = ENUM_5_VAL_6;
    inst_ST_15.ST_15_member_4 = ENUM_13_VAL_1;
    inst_ST_15.ST_15_member_5 = ENUM_10_VAL_0;
    inst_ST_15.ST_15_member_6 = ENUM_27_VAL_6;
    inst_ST_15.ST_15_member_7 = ENUM_12_VAL_6;
    inst_ST_15.ST_15_member_8 = ENUM_11_VAL_3;
    inst_ST_15.ST_15_member_9 = ENUM_24_VAL_3;
    __attribute__((unused)) ST_16 inst_ST_16 {};
    inst_ST_16.ST_16_member_0 = ENUM_7_VAL_4;
    inst_ST_16.ST_16_member_1 = 43;
    inst_ST_16.ST_16_member_2 = ENUM_2_VAL_6;
    inst_ST_16.ST_16_member_3 = ENUM_17_VAL_8;
    inst_ST_16.ST_16_member_4 = 97;
    inst_ST_16.ST_16_member_5 = ENUM_11_VAL_5;
    inst_ST_16.ST_16_member_6 = ENUM_9_VAL_3;
    inst_ST_16.ST_16_member_7 = ENUM_10_VAL_9;
    inst_ST_16.ST_16_member_8 = ENUM_11_VAL_4;
    inst_ST_16.ST_16_member_9 = ENUM_2_VAL_7;
    __attribute__((unused)) ST_17 inst_ST_17 {};
    inst_ST_17.ST_17_member_0 = ENUM_19_VAL_0;
    inst_ST_17.ST_17_member_1 = 47;
    inst_ST_17.ST_17_member_2 = ENUM_14_VAL_1;
    inst_ST_17.ST_17_member_3 = ENUM_5_VAL_8;
    inst_ST_17.ST_17_member_4 = ENUM_5_VAL_6;
    inst_ST_17.ST_17_member_5 = ENUM_1_VAL_6;
    inst_ST_17.ST_17_member_6 = ENUM_10_VAL_8;
    inst_ST_17.ST_17_member_7 = ENUM_5_VAL_9;
    inst_ST_17.ST_17_member_8 = ENUM_13_VAL_3;
    inst_ST_17.ST_17_member_9 = ENUM_16_VAL_9;
    __attribute__((unused)) ST_18 inst_ST_18 {};
    inst_ST_18.ST_18_member_0 = ENUM_1_VAL_5;
    inst_ST_18.ST_18_member_1 = ENUM_9_VAL_2;
    inst_ST_18.ST_18_member_2 = ENUM_4_VAL_8;
    inst_ST_18.ST_18_member_3 = ENUM_6_VAL_3;
    inst_ST_18.ST_18_member_4 = ENUM_16_VAL_9;
    inst_ST_18.ST_18_member_5 = ENUM_9_VAL_3;
    inst_ST_18.ST_18_member_6 = ENUM_10_VAL_2;
    inst_ST_18.ST_18_member_7 = ENUM_12_VAL_4;
    inst_ST_18.ST_18_member_8 = 13;
    inst_ST_18.ST_18_member_9 = 30;
    __attribute__((unused)) ST_19 inst_ST_19 {};
    inst_ST_19.ST_19_member_0 = ENUM_11_VAL_5;
    inst_ST_19.ST_19_member_1 = ENUM_20_VAL_1;
    inst_ST_19.ST_19_member_2 = ENUM_6_VAL_1;
    inst_ST_19.ST_19_member_3 = ENUM_11_VAL_9;
    inst_ST_19.ST_19_member_4 = 31;
    inst_ST_19.ST_19_member_5 = ENUM_12_VAL_0;
    inst_ST_19.ST_19_member_6 = ENUM_5_VAL_6;
    inst_ST_19.ST_19_member_7 = 35;
    inst_ST_19.ST_19_member_8 = ENUM_12_VAL_4;
    inst_ST_19.ST_19_member_9 = ENUM_0_VAL_9;
    hal_func_2(&inst_ST_14);
    hal_func_9(&inst_ST_7);
    hal_func_1(&inst_ST_18);
    hal_func_3(&inst_ST_1);
    hal_func_9(&inst_ST_7);
    hal_func_1(&inst_ST_18);
    hal_func_5(&inst_ST_5);
    hal_func_2(&inst_ST_14);
    hal_func_5(&inst_ST_5);
    hal_func_7(&inst_ST_1);

    volatile int a;
    volatile int b;
    Cclass_0 instance_class_0 {};
    Cclass_0_User user_class_0 { &instance_class_0 };
    a = user_class_0.use_func_a();
    b = user_class_0.use_func_b();
    Cclass_1 instance_class_1 {};
    Cclass_1_User user_class_1 { &instance_class_1 };
    a = user_class_1.use_func_a();
    b = user_class_1.use_func_b();
    Cclass_2 instance_class_2 {};
    Cclass_2_User user_class_2 { &instance_class_2 };
    a = user_class_2.use_func_a();
    b = user_class_2.use_func_b();
    Cclass_3 instance_class_3 {};
    Cclass_3_User user_class_3 { &instance_class_3 };
    a = user_class_3.use_func_a();
    b = user_class_3.use_func_b();
    Cclass_4 instance_class_4 {};
    Cclass_4_User user_class_4 { &instance_class_4 };
    a = user_class_4.use_func_a();
    b = user_class_4.use_func_b();
    Cclass_5 instance_class_5 {};
    Cclass_5_User user_class_5 { &instance_class_5 };
    a = user_class_5.use_func_a();
    b = user_class_5.use_func_b();
    Cclass_6 instance_class_6 {};
    Cclass_6_User user_class_6 { &instance_class_6 };
    a = user_class_6.use_func_a();
    b = user_class_6.use_func_b();
    Cclass_7 instance_class_7 {};
    Cclass_7_User user_class_7 { &instance_class_7 };
    a = user_class_7.use_func_a();
    b = user_class_7.use_func_b();
    Cclass_8 instance_class_8 {};
    Cclass_8_User user_class_8 { &instance_class_8 };
    a = user_class_8.use_func_a();
    b = user_class_8.use_func_b();
    Cclass_9 instance_class_9 {};
    Cclass_9_User user_class_9 { &instance_class_9 };
    a = user_class_9.use_func_a();
    b = user_class_9.use_func_b();
    Cclass_10 instance_class_10 {};
    Cclass_10_User user_class_10 { &instance_class_10 };
    a = user_class_10.use_func_a();
    b = user_class_10.use_func_b();
    Cclass_11 instance_class_11 {};
    Cclass_11_User user_class_11 { &instance_class_11 };
    a = user_class_11.use_func_a();
    b = user_class_11.use_func_b();
    Cclass_12 instance_class_12 {};
    Cclass_12_User user_class_12 { &instance_class_12 };
    a = user_class_12.use_func_a();
    b = user_class_12.use_func_b();
    Cclass_13 instance_class_13 {};
    Cclass_13_User user_class_13 { &instance_class_13 };
    a = user_class_13.use_func_a();
    b = user_class_13.use_func_b();
    Cclass_14 instance_class_14 {};
    Cclass_14_User user_class_14 { &instance_class_14 };
    a = user_class_14.use_func_a();
    b = user_class_14.use_func_b();
    Cclass_15 instance_class_15 {};
    Cclass_15_User user_class_15 { &instance_class_15 };
    a = user_class_15.use_func_a();
    b = user_class_15.use_func_b();
    Cclass_16 instance_class_16 {};
    Cclass_16_User user_class_16 { &instance_class_16 };
    a = user_class_16.use_func_a();
    b = user_class_16.use_func_b();
    Cclass_17 instance_class_17 {};
    Cclass_17_User user_class_17 { &instance_class_17 };
    a = user_class_17.use_func_a();
    b = user_class_17.use_func_b();
    Cclass_18 instance_class_18 {};
    Cclass_18_User user_class_18 { &instance_class_18 };
    a = user_class_18.use_func_a();
    b = user_class_18.use_func_b();
    Cclass_19 instance_class_19 {};
    Cclass_19_User user_class_19 { &instance_class_19 };
    a = user_class_19.use_func_a();
    b = user_class_19.use_func_b();
    Cclass_20 instance_class_20 {};
    Cclass_20_User user_class_20 { &instance_class_20 };
    a = user_class_20.use_func_a();
    b = user_class_20.use_func_b();
    Cclass_21 instance_class_21 {};
    Cclass_21_User user_class_21 { &instance_class_21 };
    a = user_class_21.use_func_a();
    b = user_class_21.use_func_b();
    Cclass_22 instance_class_22 {};
    Cclass_22_User user_class_22 { &instance_class_22 };
    a = user_class_22.use_func_a();
    b = user_class_22.use_func_b();
    Cclass_23 instance_class_23 {};
    Cclass_23_User user_class_23 { &instance_class_23 };
    a = user_class_23.use_func_a();
    b = user_class_23.use_func_b();
    Cclass_24 instance_class_24 {};
    Cclass_24_User user_class_24 { &instance_class_24 };
    a = user_class_24.use_func_a();
    b = user_class_24.use_func_b();
    Cclass_25 instance_class_25 {};
    Cclass_25_User user_class_25 { &instance_class_25 };
    a = user_class_25.use_func_a();
    b = user_class_25.use_func_b();
    Cclass_26 instance_class_26 {};
    Cclass_26_User user_class_26 { &instance_class_26 };
    a = user_class_26.use_func_a();
    b = user_class_26.use_func_b();
    Cclass_27 instance_class_27 {};
    Cclass_27_User user_class_27 { &instance_class_27 };
    a = user_class_27.use_func_a();
    b = user_class_27.use_func_b();
    Cclass_28 instance_class_28 {};
    Cclass_28_User user_class_28 { &instance_class_28 };
    a = user_class_28.use_func_a();
    b = user_class_28.use_func_b();
    Cclass_29 instance_class_29 {};
    Cclass_29_User user_class_29 { &instance_class_29 };
    a = user_class_29.use_func_a();
    b = user_class_29.use_func_b();
    Cclass_30 instance_class_30 {};
    Cclass_30_User user_class_30 { &instance_class_30 };
    a = user_class_30.use_func_a();
    b = user_class_30.use_func_b();
    Cclass_31 instance_class_31 {};
    Cclass_31_User user_class_31 { &instance_class_31 };
    a = user_class_31.use_func_a();
    b = user_class_31.use_func_b();
    Cclass_32 instance_class_32 {};
    Cclass_32_User user_class_32 { &instance_class_32 };
    a = user_class_32.use_func_a();
    b = user_class_32.use_func_b();
    Cclass_33 instance_class_33 {};
    Cclass_33_User user_class_33 { &instance_class_33 };
    a = user_class_33.use_func_a();
    b = user_class_33.use_func_b();
    Cclass_34 instance_class_34 {};
    Cclass_34_User user_class_34 { &instance_class_34 };
    a = user_class_34.use_func_a();
    b = user_class_34.use_func_b();
    Cclass_35 instance_class_35 {};
    Cclass_35_User user_class_35 { &instance_class_35 };
    a = user_class_35.use_func_a();
    b = user_class_35.use_func_b();
    Cclass_36 instance_class_36 {};
    Cclass_36_User user_class_36 { &instance_class_36 };
    a = user_class_36.use_func_a();
    b = user_class_36.use_func_b();
    Cclass_37 instance_class_37 {};
    Cclass_37_User user_class_37 { &instance_class_37 };
    a = user_class_37.use_func_a();
    b = user_class_37.use_func_b();
    Cclass_38 instance_class_38 {};
    Cclass_38_User user_class_38 { &instance_class_38 };
    a = user_class_38.use_func_a();
    b = user_class_38.use_func_b();
    Cclass_39 instance_class_39 {};
    Cclass_39_User user_class_39 { &instance_class_39 };
    a = user_class_39.use_func_a();
    b = user_class_39.use_func_b();
    Cclass_40 instance_class_40 {};
    Cclass_40_User user_class_40 { &instance_class_40 };
    a = user_class_40.use_func_a();
    b = user_class_40.use_func_b();
    Cclass_41 instance_class_41 {};
    Cclass_41_User user_class_41 { &instance_class_41 };
    a = user_class_41.use_func_a();
    b = user_class_41.use_func_b();
    Cclass_42 instance_class_42 {};
    Cclass_42_User user_class_42 { &instance_class_42 };
    a = user_class_42.use_func_a();
    b = user_class_42.use_func_b();
    Cclass_43 instance_class_43 {};
    Cclass_43_User user_class_43 { &instance_class_43 };
    a = user_class_43.use_func_a();
    b = user_class_43.use_func_b();
    Cclass_44 instance_class_44 {};
    Cclass_44_User user_class_44 { &instance_class_44 };
    a = user_class_44.use_func_a();
    b = user_class_44.use_func_b();
    Cclass_45 instance_class_45 {};
    Cclass_45_User user_class_45 { &instance_class_45 };
    a = user_class_45.use_func_a();
    b = user_class_45.use_func_b();
    Cclass_46 instance_class_46 {};
    Cclass_46_User user_class_46 { &instance_class_46 };
    a = user_class_46.use_func_a();
    b = user_class_46.use_func_b();
    Cclass_47 instance_class_47 {};
    Cclass_47_User user_class_47 { &instance_class_47 };
    a = user_class_47.use_func_a();
    b = user_class_47.use_func_b();
    Cclass_48 instance_class_48 {};
    Cclass_48_User user_class_48 { &instance_class_48 };
    a = user_class_48.use_func_a();
    b = user_class_48.use_func_b();
    Cclass_49 instance_class_49 {};
    Cclass_49_User user_class_49 { &instance_class_49 };
    a = user_class_49.use_func_a();
    b = user_class_49.use_func_b();
    Cclass_50 instance_class_50 {};
    Cclass_50_User user_class_50 { &instance_class_50 };
    a = user_class_50.use_func_a();
    b = user_class_50.use_func_b();
    Cclass_51 instance_class_51 {};
    Cclass_51_User user_class_51 { &instance_class_51 };
    a = user_class_51.use_func_a();
    b = user_class_51.use_func_b();
    Cclass_52 instance_class_52 {};
    Cclass_52_User user_class_52 { &instance_class_52 };
    a = user_class_52.use_func_a();
    b = user_class_52.use_func_b();
    Cclass_53 instance_class_53 {};
    Cclass_53_User user_class_53 { &instance_class_53 };
    a = user_class_53.use_func_a();
    b = user_class_53.use_func_b();
    Cclass_54 instance_class_54 {};
    Cclass_54_User user_class_54 { &instance_class_54 };
    a = user_class_54.use_func_a();
    b = user_class_54.use_func_b();
    Cclass_55 instance_class_55 {};
    Cclass_55_User user_class_55 { &instance_class_55 };
    a = user_class_55.use_func_a();
    b = user_class_55.use_func_b();
    Cclass_56 instance_class_56 {};
    Cclass_56_User user_class_56 { &instance_class_56 };
    a = user_class_56.use_func_a();
    b = user_class_56.use_func_b();
    Cclass_57 instance_class_57 {};
    Cclass_57_User user_class_57 { &instance_class_57 };
    a = user_class_57.use_func_a();
    b = user_class_57.use_func_b();
    Cclass_58 instance_class_58 {};
    Cclass_58_User user_class_58 { &instance_class_58 };
    a = user_class_58.use_func_a();
    b = user_class_58.use_func_b();
    Cclass_59 instance_class_59 {};
    Cclass_59_User user_class_59 { &instance_class_59 };
    a = user_class_59.use_func_a();
    b = user_class_59.use_func_b();
    Cclass_60 instance_class_60 {};
    Cclass_60_User user_class_60 { &instance_class_60 };
    a = user_class_60.use_func_a();
    b = user_class_60.use_func_b();
    Cclass_61 instance_class_61 {};
    Cclass_61_User user_class_61 { &instance_class_61 };
    a = user_class_61.use_func_a();
    b = user_class_61.use_func_b();
    Cclass_62 instance_class_62 {};
    Cclass_62_User user_class_62 { &instance_class_62 };
    a = user_class_62.use_func_a();
    b = user_class_62.use_func_b();
    Cclass_63 instance_class_63 {};
    Cclass_63_User user_class_63 { &instance_class_63 };
    a = user_class_63.use_func_a();
    b = user_class_63.use_func_b();
    Cclass_64 instance_class_64 {};
    Cclass_64_User user_class_64 { &instance_class_64 };
    a = user_class_64.use_func_a();
    b = user_class_64.use_func_b();
    Cclass_65 instance_class_65 {};
    Cclass_65_User user_class_65 { &instance_class_65 };
    a = user_class_65.use_func_a();
    b = user_class_65.use_func_b();
    Cclass_66 instance_class_66 {};
    Cclass_66_User user_class_66 { &instance_class_66 };
    a = user_class_66.use_func_a();
    b = user_class_66.use_func_b();
    Cclass_67 instance_class_67 {};
    Cclass_67_User user_class_67 { &instance_class_67 };
    a = user_class_67.use_func_a();
    b = user_class_67.use_func_b();
    Cclass_68 instance_class_68 {};
    Cclass_68_User user_class_68 { &instance_class_68 };
    a = user_class_68.use_func_a();
    b = user_class_68.use_func_b();
    Cclass_69 instance_class_69 {};
    Cclass_69_User user_class_69 { &instance_class_69 };
    a = user_class_69.use_func_a();
    b = user_class_69.use_func_b();
    Cclass_70 instance_class_70 {};
    Cclass_70_User user_class_70 { &instance_class_70 };
    a = user_class_70.use_func_a();
    b = user_class_70.use_func_b();
    Cclass_71 instance_class_71 {};
    Cclass_71_User user_class_71 { &instance_class_71 };
    a = user_class_71.use_func_a();
    b = user_class_71.use_func_b();
    Cclass_72 instance_class_72 {};
    Cclass_72_User user_class_72 { &instance_class_72 };
    a = user_class_72.use_func_a();
    b = user_class_72.use_func_b();
    Cclass_73 instance_class_73 {};
    Cclass_73_User user_class_73 { &instance_class_73 };
    a = user_class_73.use_func_a();
    b = user_class_73.use_func_b();
    Cclass_74 instance_class_74 {};
    Cclass_74_User user_class_74 { &instance_class_74 };
    a = user_class_74.use_func_a();
    b = user_class_74.use_func_b();
    Cclass_75 instance_class_75 {};
    Cclass_75_User user_class_75 { &instance_class_75 };
    a = user_class_75.use_func_a();
    b = user_class_75.use_func_b();
    Cclass_76 instance_class_76 {};
    Cclass_76_User user_class_76 { &instance_class_76 };
    a = user_class_76.use_func_a();
    b = user_class_76.use_func_b();
    Cclass_77 instance_class_77 {};
    Cclass_77_User user_class_77 { &instance_class_77 };
    a = user_class_77.use_func_a();
    b = user_class_77.use_func_b();
    Cclass_78 instance_class_78 {};
    Cclass_78_User user_class_78 { &instance_class_78 };
    a = user_class_78.use_func_a();
    b = user_class_78.use_func_b();
    Cclass_79 instance_class_79 {};
    Cclass_79_User user_class_79 { &instance_class_79 };
    a = user_class_79.use_func_a();
    b = user_class_79.use_func_b();
    Cclass_80 instance_class_80 {};
    Cclass_80_User user_class_80 { &instance_class_80 };
    a = user_class_80.use_func_a();
    b = user_class_80.use_func_b();
    Cclass_81 instance_class_81 {};
    Cclass_81_User user_class_81 { &instance_class_81 };
    a = user_class_81.use_func_a();
    b = user_class_81.use_func_b();
    Cclass_82 instance_class_82 {};
    Cclass_82_User user_class_82 { &instance_class_82 };
    a = user_class_82.use_func_a();
    b = user_class_82.use_func_b();
    Cclass_83 instance_class_83 {};
    Cclass_83_User user_class_83 { &instance_class_83 };
    a = user_class_83.use_func_a();
    b = user_class_83.use_func_b();
    Cclass_84 instance_class_84 {};
    Cclass_84_User user_class_84 { &instance_class_84 };
    a = user_class_84.use_func_a();
    b = user_class_84.use_func_b();
    Cclass_85 instance_class_85 {};
    Cclass_85_User user_class_85 { &instance_class_85 };
    a = user_class_85.use_func_a();
    b = user_class_85.use_func_b();
    Cclass_86 instance_class_86 {};
    Cclass_86_User user_class_86 { &instance_class_86 };
    a = user_class_86.use_func_a();
    b = user_class_86.use_func_b();
    Cclass_87 instance_class_87 {};
    Cclass_87_User user_class_87 { &instance_class_87 };
    a = user_class_87.use_func_a();
    b = user_class_87.use_func_b();
    Cclass_88 instance_class_88 {};
    Cclass_88_User user_class_88 { &instance_class_88 };
    a = user_class_88.use_func_a();
    b = user_class_88.use_func_b();
    Cclass_89 instance_class_89 {};
    Cclass_89_User user_class_89 { &instance_class_89 };
    a = user_class_89.use_func_a();
    b = user_class_89.use_func_b();
    Cclass_90 instance_class_90 {};
    Cclass_90_User user_class_90 { &instance_class_90 };
    a = user_class_90.use_func_a();
    b = user_class_90.use_func_b();
    Cclass_91 instance_class_91 {};
    Cclass_91_User user_class_91 { &instance_class_91 };
    a = user_class_91.use_func_a();
    b = user_class_91.use_func_b();
    Cclass_92 instance_class_92 {};
    Cclass_92_User user_class_92 { &instance_class_92 };
    a = user_class_92.use_func_a();
    b = user_class_92.use_func_b();
    Cclass_93 instance_class_93 {};
    Cclass_93_User user_class_93 { &instance_class_93 };
    a = user_class_93.use_func_a();
    b = user_class_93.use_func_b();
    Cclass_94 instance_class_94 {};
    Cclass_94_User user_class_94 { &instance_class_94 };
    a = user_class_94.use_func_a();
    b = user_class_94.use_func_b();
    Cclass_95 instance_class_95 {};
    Cclass_95_User user_class_95 { &instance_class_95 };
    a = user_class_95.use_func_a();
    b = user_class_95.use_func_b();
    Cclass_96 instance_class_96 {};
    Cclass_96_User user_class_96 { &instance_class_96 };
    a = user_class_96.use_func_a();
    b = user_class_96.use_func_b();
    Cclass_97 instance_class_97 {};
    Cclass_97_User user_class_97 { &instance_class_97 };
    a = user_class_97.use_func_a();
    b = user_class_97.use_func_b();
    Cclass_98 instance_class_98 {};
    Cclass_98_User user_class_98 { &instance_class_98 };
    a = user_class_98.use_func_a();
    b = user_class_98.use_func_b();
    Cclass_99 instance_class_99 {};
    Cclass_99_User user_class_99 { &instance_class_99 };
    a = user_class_99.use_func_a();
    b = user_class_99.use_func_b();
    Cclass_100 instance_class_100 {};
    Cclass_100_User user_class_100 { &instance_class_100 };
    a = user_class_100.use_func_a();
    b = user_class_100.use_func_b();
    Cclass_101 instance_class_101 {};
    Cclass_101_User user_class_101 { &instance_class_101 };
    a = user_class_101.use_func_a();
    b = user_class_101.use_func_b();
    Cclass_102 instance_class_102 {};
    Cclass_102_User user_class_102 { &instance_class_102 };
    a = user_class_102.use_func_a();
    b = user_class_102.use_func_b();
    Cclass_103 instance_class_103 {};
    Cclass_103_User user_class_103 { &instance_class_103 };
    a = user_class_103.use_func_a();
    b = user_class_103.use_func_b();
    Cclass_104 instance_class_104 {};
    Cclass_104_User user_class_104 { &instance_class_104 };
    a = user_class_104.use_func_a();
    b = user_class_104.use_func_b();
    Cclass_105 instance_class_105 {};
    Cclass_105_User user_class_105 { &instance_class_105 };
    a = user_class_105.use_func_a();
    b = user_class_105.use_func_b();
    Cclass_106 instance_class_106 {};
    Cclass_106_User user_class_106 { &instance_class_106 };
    a = user_class_106.use_func_a();
    b = user_class_106.use_func_b();
    Cclass_107 instance_class_107 {};
    Cclass_107_User user_class_107 { &instance_class_107 };
    a = user_class_107.use_func_a();
    b = user_class_107.use_func_b();
    Cclass_108 instance_class_108 {};
    Cclass_108_User user_class_108 { &instance_class_108 };
    a = user_class_108.use_func_a();
    b = user_class_108.use_func_b();
    Cclass_109 instance_class_109 {};
    Cclass_109_User user_class_109 { &instance_class_109 };
    a = user_class_109.use_func_a();
    b = user_class_109.use_func_b();
    Cclass_110 instance_class_110 {};
    Cclass_110_User user_class_110 { &instance_class_110 };
    a = user_class_110.use_func_a();
    b = user_class_110.use_func_b();
    Cclass_111 instance_class_111 {};
    Cclass_111_User user_class_111 { &instance_class_111 };
    a = user_class_111.use_func_a();
    b = user_class_111.use_func_b();
    Cclass_112 instance_class_112 {};
    Cclass_112_User user_class_112 { &instance_class_112 };
    a = user_class_112.use_func_a();
    b = user_class_112.use_func_b();
    Cclass_113 instance_class_113 {};
    Cclass_113_User user_class_113 { &instance_class_113 };
    a = user_class_113.use_func_a();
    b = user_class_113.use_func_b();
    Cclass_114 instance_class_114 {};
    Cclass_114_User user_class_114 { &instance_class_114 };
    a = user_class_114.use_func_a();
    b = user_class_114.use_func_b();
    Cclass_115 instance_class_115 {};
    Cclass_115_User user_class_115 { &instance_class_115 };
    a = user_class_115.use_func_a();
    b = user_class_115.use_func_b();
    Cclass_116 instance_class_116 {};
    Cclass_116_User user_class_116 { &instance_class_116 };
    a = user_class_116.use_func_a();
    b = user_class_116.use_func_b();
    Cclass_117 instance_class_117 {};
    Cclass_117_User user_class_117 { &instance_class_117 };
    a = user_class_117.use_func_a();
    b = user_class_117.use_func_b();
    Cclass_118 instance_class_118 {};
    Cclass_118_User user_class_118 { &instance_class_118 };
    a = user_class_118.use_func_a();
    b = user_class_118.use_func_b();
    Cclass_119 instance_class_119 {};
    Cclass_119_User user_class_119 { &instance_class_119 };
    a = user_class_119.use_func_a();
    b = user_class_119.use_func_b();
    Cclass_120 instance_class_120 {};
    Cclass_120_User user_class_120 { &instance_class_120 };
    a = user_class_120.use_func_a();
    b = user_class_120.use_func_b();
    Cclass_121 instance_class_121 {};
    Cclass_121_User user_class_121 { &instance_class_121 };
    a = user_class_121.use_func_a();
    b = user_class_121.use_func_b();
    Cclass_122 instance_class_122 {};
    Cclass_122_User user_class_122 { &instance_class_122 };
    a = user_class_122.use_func_a();
    b = user_class_122.use_func_b();
    Cclass_123 instance_class_123 {};
    Cclass_123_User user_class_123 { &instance_class_123 };
    a = user_class_123.use_func_a();
    b = user_class_123.use_func_b();
    Cclass_124 instance_class_124 {};
    Cclass_124_User user_class_124 { &instance_class_124 };
    a = user_class_124.use_func_a();
    b = user_class_124.use_func_b();
    Cclass_125 instance_class_125 {};
    Cclass_125_User user_class_125 { &instance_class_125 };
    a = user_class_125.use_func_a();
    b = user_class_125.use_func_b();
    Cclass_126 instance_class_126 {};
    Cclass_126_User user_class_126 { &instance_class_126 };
    a = user_class_126.use_func_a();
    b = user_class_126.use_func_b();
    Cclass_127 instance_class_127 {};
    Cclass_127_User user_class_127 { &instance_class_127 };
    a = user_class_127.use_func_a();
    b = user_class_127.use_func_b();
    Cclass_128 instance_class_128 {};
    Cclass_128_User user_class_128 { &instance_class_128 };
    a = user_class_128.use_func_a();
    b = user_class_128.use_func_b();
    Cclass_129 instance_class_129 {};
    Cclass_129_User user_class_129 { &instance_class_129 };
    a = user_class_129.use_func_a();
    b = user_class_129.use_func_b();
    Cclass_130 instance_class_130 {};
    Cclass_130_User user_class_130 { &instance_class_130 };
    a = user_class_130.use_func_a();
    b = user_class_130.use_func_b();
    Cclass_131 instance_class_131 {};
    Cclass_131_User user_class_131 { &instance_class_131 };
    a = user_class_131.use_func_a();
    b = user_class_131.use_func_b();
    Cclass_132 instance_class_132 {};
    Cclass_132_User user_class_132 { &instance_class_132 };
    a = user_class_132.use_func_a();
    b = user_class_132.use_func_b();
    Cclass_133 instance_class_133 {};
    Cclass_133_User user_class_133 { &instance_class_133 };
    a = user_class_133.use_func_a();
    b = user_class_133.use_func_b();
    Cclass_134 instance_class_134 {};
    Cclass_134_User user_class_134 { &instance_class_134 };
    a = user_class_134.use_func_a();
    b = user_class_134.use_func_b();
    Cclass_135 instance_class_135 {};
    Cclass_135_User user_class_135 { &instance_class_135 };
    a = user_class_135.use_func_a();
    b = user_class_135.use_func_b();
    Cclass_136 instance_class_136 {};
    Cclass_136_User user_class_136 { &instance_class_136 };
    a = user_class_136.use_func_a();
    b = user_class_136.use_func_b();
    Cclass_137 instance_class_137 {};
    Cclass_137_User user_class_137 { &instance_class_137 };
    a = user_class_137.use_func_a();
    b = user_class_137.use_func_b();
    Cclass_138 instance_class_138 {};
    Cclass_138_User user_class_138 { &instance_class_138 };
    a = user_class_138.use_func_a();
    b = user_class_138.use_func_b();
    Cclass_139 instance_class_139 {};
    Cclass_139_User user_class_139 { &instance_class_139 };
    a = user_class_139.use_func_a();
    b = user_class_139.use_func_b();
    Cclass_140 instance_class_140 {};
    Cclass_140_User user_class_140 { &instance_class_140 };
    a = user_class_140.use_func_a();
    b = user_class_140.use_func_b();
    Cclass_141 instance_class_141 {};
    Cclass_141_User user_class_141 { &instance_class_141 };
    a = user_class_141.use_func_a();
    b = user_class_141.use_func_b();
    Cclass_142 instance_class_142 {};
    Cclass_142_User user_class_142 { &instance_class_142 };
    a = user_class_142.use_func_a();
    b = user_class_142.use_func_b();
    Cclass_143 instance_class_143 {};
    Cclass_143_User user_class_143 { &instance_class_143 };
    a = user_class_143.use_func_a();
    b = user_class_143.use_func_b();
    Cclass_144 instance_class_144 {};
    Cclass_144_User user_class_144 { &instance_class_144 };
    a = user_class_144.use_func_a();
    b = user_class_144.use_func_b();
    Cclass_145 instance_class_145 {};
    Cclass_145_User user_class_145 { &instance_class_145 };
    a = user_class_145.use_func_a();
    b = user_class_145.use_func_b();
    Cclass_146 instance_class_146 {};
    Cclass_146_User user_class_146 { &instance_class_146 };
    a = user_class_146.use_func_a();
    b = user_class_146.use_func_b();
    Cclass_147 instance_class_147 {};
    Cclass_147_User user_class_147 { &instance_class_147 };
    a = user_class_147.use_func_a();
    b = user_class_147.use_func_b();
    Cclass_148 instance_class_148 {};
    Cclass_148_User user_class_148 { &instance_class_148 };
    a = user_class_148.use_func_a();
    b = user_class_148.use_func_b();
    Cclass_149 instance_class_149 {};
    Cclass_149_User user_class_149 { &instance_class_149 };
    a = user_class_149.use_func_a();
    b = user_class_149.use_func_b();
    Cclass_150 instance_class_150 {};
    Cclass_150_User user_class_150 { &instance_class_150 };
    a = user_class_150.use_func_a();
    b = user_class_150.use_func_b();
    Cclass_151 instance_class_151 {};
    Cclass_151_User user_class_151 { &instance_class_151 };
    a = user_class_151.use_func_a();
    b = user_class_151.use_func_b();
    Cclass_152 instance_class_152 {};
    Cclass_152_User user_class_152 { &instance_class_152 };
    a = user_class_152.use_func_a();
    b = user_class_152.use_func_b();
    Cclass_153 instance_class_153 {};
    Cclass_153_User user_class_153 { &instance_class_153 };
    a = user_class_153.use_func_a();
    b = user_class_153.use_func_b();
    Cclass_154 instance_class_154 {};
    Cclass_154_User user_class_154 { &instance_class_154 };
    a = user_class_154.use_func_a();
    b = user_class_154.use_func_b();
    Cclass_155 instance_class_155 {};
    Cclass_155_User user_class_155 { &instance_class_155 };
    a = user_class_155.use_func_a();
    b = user_class_155.use_func_b();
    Cclass_156 instance_class_156 {};
    Cclass_156_User user_class_156 { &instance_class_156 };
    a = user_class_156.use_func_a();
    b = user_class_156.use_func_b();
    Cclass_157 instance_class_157 {};
    Cclass_157_User user_class_157 { &instance_class_157 };
    a = user_class_157.use_func_a();
    b = user_class_157.use_func_b();
    Cclass_158 instance_class_158 {};
    Cclass_158_User user_class_158 { &instance_class_158 };
    a = user_class_158.use_func_a();
    b = user_class_158.use_func_b();
    Cclass_159 instance_class_159 {};
    Cclass_159_User user_class_159 { &instance_class_159 };
    a = user_class_159.use_func_a();
    b = user_class_159.use_func_b();
    Cclass_160 instance_class_160 {};
    Cclass_160_User user_class_160 { &instance_class_160 };
    a = user_class_160.use_func_a();
    b = user_class_160.use_func_b();
    Cclass_161 instance_class_161 {};
    Cclass_161_User user_class_161 { &instance_class_161 };
    a = user_class_161.use_func_a();
    b = user_class_161.use_func_b();
    Cclass_162 instance_class_162 {};
    Cclass_162_User user_class_162 { &instance_class_162 };
    a = user_class_162.use_func_a();
    b = user_class_162.use_func_b();
    Cclass_163 instance_class_163 {};
    Cclass_163_User user_class_163 { &instance_class_163 };
    a = user_class_163.use_func_a();
    b = user_class_163.use_func_b();
    Cclass_164 instance_class_164 {};
    Cclass_164_User user_class_164 { &instance_class_164 };
    a = user_class_164.use_func_a();
    b = user_class_164.use_func_b();
    Cclass_165 instance_class_165 {};
    Cclass_165_User user_class_165 { &instance_class_165 };
    a = user_class_165.use_func_a();
    b = user_class_165.use_func_b();
    Cclass_166 instance_class_166 {};
    Cclass_166_User user_class_166 { &instance_class_166 };
    a = user_class_166.use_func_a();
    b = user_class_166.use_func_b();
    Cclass_167 instance_class_167 {};
    Cclass_167_User user_class_167 { &instance_class_167 };
    a = user_class_167.use_func_a();
    b = user_class_167.use_func_b();
    Cclass_168 instance_class_168 {};
    Cclass_168_User user_class_168 { &instance_class_168 };
    a = user_class_168.use_func_a();
    b = user_class_168.use_func_b();
    Cclass_169 instance_class_169 {};
    Cclass_169_User user_class_169 { &instance_class_169 };
    a = user_class_169.use_func_a();
    b = user_class_169.use_func_b();
    Cclass_170 instance_class_170 {};
    Cclass_170_User user_class_170 { &instance_class_170 };
    a = user_class_170.use_func_a();
    b = user_class_170.use_func_b();
    Cclass_171 instance_class_171 {};
    Cclass_171_User user_class_171 { &instance_class_171 };
    a = user_class_171.use_func_a();
    b = user_class_171.use_func_b();
    Cclass_172 instance_class_172 {};
    Cclass_172_User user_class_172 { &instance_class_172 };
    a = user_class_172.use_func_a();
    b = user_class_172.use_func_b();
    Cclass_173 instance_class_173 {};
    Cclass_173_User user_class_173 { &instance_class_173 };
    a = user_class_173.use_func_a();
    b = user_class_173.use_func_b();
    Cclass_174 instance_class_174 {};
    Cclass_174_User user_class_174 { &instance_class_174 };
    a = user_class_174.use_func_a();
    b = user_class_174.use_func_b();
    Cclass_175 instance_class_175 {};
    Cclass_175_User user_class_175 { &instance_class_175 };
    a = user_class_175.use_func_a();
    b = user_class_175.use_func_b();
    Cclass_176 instance_class_176 {};
    Cclass_176_User user_class_176 { &instance_class_176 };
    a = user_class_176.use_func_a();
    b = user_class_176.use_func_b();
    Cclass_177 instance_class_177 {};
    Cclass_177_User user_class_177 { &instance_class_177 };
    a = user_class_177.use_func_a();
    b = user_class_177.use_func_b();
    Cclass_178 instance_class_178 {};
    Cclass_178_User user_class_178 { &instance_class_178 };
    a = user_class_178.use_func_a();
    b = user_class_178.use_func_b();
    Cclass_179 instance_class_179 {};
    Cclass_179_User user_class_179 { &instance_class_179 };
    a = user_class_179.use_func_a();
    b = user_class_179.use_func_b();
    Cclass_180 instance_class_180 {};
    Cclass_180_User user_class_180 { &instance_class_180 };
    a = user_class_180.use_func_a();
    b = user_class_180.use_func_b();
    Cclass_181 instance_class_181 {};
    Cclass_181_User user_class_181 { &instance_class_181 };
    a = user_class_181.use_func_a();
    b = user_class_181.use_func_b();
    Cclass_182 instance_class_182 {};
    Cclass_182_User user_class_182 { &instance_class_182 };
    a = user_class_182.use_func_a();
    b = user_class_182.use_func_b();
    Cclass_183 instance_class_183 {};
    Cclass_183_User user_class_183 { &instance_class_183 };
    a = user_class_183.use_func_a();
    b = user_class_183.use_func_b();
    Cclass_184 instance_class_184 {};
    Cclass_184_User user_class_184 { &instance_class_184 };
    a = user_class_184.use_func_a();
    b = user_class_184.use_func_b();
    Cclass_185 instance_class_185 {};
    Cclass_185_User user_class_185 { &instance_class_185 };
    a = user_class_185.use_func_a();
    b = user_class_185.use_func_b();
    Cclass_186 instance_class_186 {};
    Cclass_186_User user_class_186 { &instance_class_186 };
    a = user_class_186.use_func_a();
    b = user_class_186.use_func_b();
    Cclass_187 instance_class_187 {};
    Cclass_187_User user_class_187 { &instance_class_187 };
    a = user_class_187.use_func_a();
    b = user_class_187.use_func_b();
    Cclass_188 instance_class_188 {};
    Cclass_188_User user_class_188 { &instance_class_188 };
    a = user_class_188.use_func_a();
    b = user_class_188.use_func_b();
    Cclass_189 instance_class_189 {};
    Cclass_189_User user_class_189 { &instance_class_189 };
    a = user_class_189.use_func_a();
    b = user_class_189.use_func_b();
    Cclass_190 instance_class_190 {};
    Cclass_190_User user_class_190 { &instance_class_190 };
    a = user_class_190.use_func_a();
    b = user_class_190.use_func_b();
    Cclass_191 instance_class_191 {};
    Cclass_191_User user_class_191 { &instance_class_191 };
    a = user_class_191.use_func_a();
    b = user_class_191.use_func_b();
    Cclass_192 instance_class_192 {};
    Cclass_192_User user_class_192 { &instance_class_192 };
    a = user_class_192.use_func_a();
    b = user_class_192.use_func_b();
    Cclass_193 instance_class_193 {};
    Cclass_193_User user_class_193 { &instance_class_193 };
    a = user_class_193.use_func_a();
    b = user_class_193.use_func_b();
    Cclass_194 instance_class_194 {};
    Cclass_194_User user_class_194 { &instance_class_194 };
    a = user_class_194.use_func_a();
    b = user_class_194.use_func_b();
    Cclass_195 instance_class_195 {};
    Cclass_195_User user_class_195 { &instance_class_195 };
    a = user_class_195.use_func_a();
    b = user_class_195.use_func_b();
    Cclass_196 instance_class_196 {};
    Cclass_196_User user_class_196 { &instance_class_196 };
    a = user_class_196.use_func_a();
    b = user_class_196.use_func_b();
    Cclass_197 instance_class_197 {};
    Cclass_197_User user_class_197 { &instance_class_197 };
    a = user_class_197.use_func_a();
    b = user_class_197.use_func_b();
    Cclass_198 instance_class_198 {};
    Cclass_198_User user_class_198 { &instance_class_198 };
    a = user_class_198.use_func_a();
    b = user_class_198.use_func_b();
    Cclass_199 instance_class_199 {};
    Cclass_199_User user_class_199 { &instance_class_199 };
    a = user_class_199.use_func_a();
    b = user_class_199.use_func_b();
    (void)a;
    (void)b;

    while (1) {}
}