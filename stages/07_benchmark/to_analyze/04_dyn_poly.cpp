#include <cstdint>

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
class Iclass_0 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_0 : public Iclass_0 {
public:
    Cclass_0 () = default;
    int func_a () override { return 1; }
    int func_b () override { return 3; }
};
class Cclass_0_User {
private:
    Iclass_0* m_class { nullptr };
public:
    Cclass_0_User (Iclass_0* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_1 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_1 : public Iclass_1 {
public:
    Cclass_1 () = default;
    int func_a () override { return 2; }
    int func_b () override { return 4; }
};
class Cclass_1_User {
private:
    Iclass_1* m_class { nullptr };
public:
    Cclass_1_User (Iclass_1* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_2 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_2 : public Iclass_2 {
public:
    Cclass_2 () = default;
    int func_a () override { return 3; }
    int func_b () override { return 5; }
};
class Cclass_2_User {
private:
    Iclass_2* m_class { nullptr };
public:
    Cclass_2_User (Iclass_2* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_3 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_3 : public Iclass_3 {
public:
    Cclass_3 () = default;
    int func_a () override { return 4; }
    int func_b () override { return 6; }
};
class Cclass_3_User {
private:
    Iclass_3* m_class { nullptr };
public:
    Cclass_3_User (Iclass_3* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_4 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_4 : public Iclass_4 {
public:
    Cclass_4 () = default;
    int func_a () override { return 5; }
    int func_b () override { return 7; }
};
class Cclass_4_User {
private:
    Iclass_4* m_class { nullptr };
public:
    Cclass_4_User (Iclass_4* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_5 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_5 : public Iclass_5 {
public:
    Cclass_5 () = default;
    int func_a () override { return 6; }
    int func_b () override { return 8; }
};
class Cclass_5_User {
private:
    Iclass_5* m_class { nullptr };
public:
    Cclass_5_User (Iclass_5* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_6 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_6 : public Iclass_6 {
public:
    Cclass_6 () = default;
    int func_a () override { return 7; }
    int func_b () override { return 9; }
};
class Cclass_6_User {
private:
    Iclass_6* m_class { nullptr };
public:
    Cclass_6_User (Iclass_6* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_7 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_7 : public Iclass_7 {
public:
    Cclass_7 () = default;
    int func_a () override { return 8; }
    int func_b () override { return 10; }
};
class Cclass_7_User {
private:
    Iclass_7* m_class { nullptr };
public:
    Cclass_7_User (Iclass_7* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_8 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_8 : public Iclass_8 {
public:
    Cclass_8 () = default;
    int func_a () override { return 9; }
    int func_b () override { return 11; }
};
class Cclass_8_User {
private:
    Iclass_8* m_class { nullptr };
public:
    Cclass_8_User (Iclass_8* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_9 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_9 : public Iclass_9 {
public:
    Cclass_9 () = default;
    int func_a () override { return 10; }
    int func_b () override { return 12; }
};
class Cclass_9_User {
private:
    Iclass_9* m_class { nullptr };
public:
    Cclass_9_User (Iclass_9* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_10 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_10 : public Iclass_10 {
public:
    Cclass_10 () = default;
    int func_a () override { return 11; }
    int func_b () override { return 13; }
};
class Cclass_10_User {
private:
    Iclass_10* m_class { nullptr };
public:
    Cclass_10_User (Iclass_10* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_11 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_11 : public Iclass_11 {
public:
    Cclass_11 () = default;
    int func_a () override { return 12; }
    int func_b () override { return 14; }
};
class Cclass_11_User {
private:
    Iclass_11* m_class { nullptr };
public:
    Cclass_11_User (Iclass_11* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_12 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_12 : public Iclass_12 {
public:
    Cclass_12 () = default;
    int func_a () override { return 13; }
    int func_b () override { return 15; }
};
class Cclass_12_User {
private:
    Iclass_12* m_class { nullptr };
public:
    Cclass_12_User (Iclass_12* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_13 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_13 : public Iclass_13 {
public:
    Cclass_13 () = default;
    int func_a () override { return 14; }
    int func_b () override { return 16; }
};
class Cclass_13_User {
private:
    Iclass_13* m_class { nullptr };
public:
    Cclass_13_User (Iclass_13* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_14 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_14 : public Iclass_14 {
public:
    Cclass_14 () = default;
    int func_a () override { return 15; }
    int func_b () override { return 17; }
};
class Cclass_14_User {
private:
    Iclass_14* m_class { nullptr };
public:
    Cclass_14_User (Iclass_14* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_15 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_15 : public Iclass_15 {
public:
    Cclass_15 () = default;
    int func_a () override { return 16; }
    int func_b () override { return 18; }
};
class Cclass_15_User {
private:
    Iclass_15* m_class { nullptr };
public:
    Cclass_15_User (Iclass_15* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_16 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_16 : public Iclass_16 {
public:
    Cclass_16 () = default;
    int func_a () override { return 17; }
    int func_b () override { return 19; }
};
class Cclass_16_User {
private:
    Iclass_16* m_class { nullptr };
public:
    Cclass_16_User (Iclass_16* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_17 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_17 : public Iclass_17 {
public:
    Cclass_17 () = default;
    int func_a () override { return 18; }
    int func_b () override { return 20; }
};
class Cclass_17_User {
private:
    Iclass_17* m_class { nullptr };
public:
    Cclass_17_User (Iclass_17* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_18 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_18 : public Iclass_18 {
public:
    Cclass_18 () = default;
    int func_a () override { return 19; }
    int func_b () override { return 21; }
};
class Cclass_18_User {
private:
    Iclass_18* m_class { nullptr };
public:
    Cclass_18_User (Iclass_18* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_19 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_19 : public Iclass_19 {
public:
    Cclass_19 () = default;
    int func_a () override { return 20; }
    int func_b () override { return 22; }
};
class Cclass_19_User {
private:
    Iclass_19* m_class { nullptr };
public:
    Cclass_19_User (Iclass_19* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_20 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_20 : public Iclass_20 {
public:
    Cclass_20 () = default;
    int func_a () override { return 21; }
    int func_b () override { return 23; }
};
class Cclass_20_User {
private:
    Iclass_20* m_class { nullptr };
public:
    Cclass_20_User (Iclass_20* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_21 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_21 : public Iclass_21 {
public:
    Cclass_21 () = default;
    int func_a () override { return 22; }
    int func_b () override { return 24; }
};
class Cclass_21_User {
private:
    Iclass_21* m_class { nullptr };
public:
    Cclass_21_User (Iclass_21* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_22 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_22 : public Iclass_22 {
public:
    Cclass_22 () = default;
    int func_a () override { return 23; }
    int func_b () override { return 25; }
};
class Cclass_22_User {
private:
    Iclass_22* m_class { nullptr };
public:
    Cclass_22_User (Iclass_22* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_23 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_23 : public Iclass_23 {
public:
    Cclass_23 () = default;
    int func_a () override { return 24; }
    int func_b () override { return 26; }
};
class Cclass_23_User {
private:
    Iclass_23* m_class { nullptr };
public:
    Cclass_23_User (Iclass_23* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_24 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_24 : public Iclass_24 {
public:
    Cclass_24 () = default;
    int func_a () override { return 25; }
    int func_b () override { return 27; }
};
class Cclass_24_User {
private:
    Iclass_24* m_class { nullptr };
public:
    Cclass_24_User (Iclass_24* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_25 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_25 : public Iclass_25 {
public:
    Cclass_25 () = default;
    int func_a () override { return 26; }
    int func_b () override { return 28; }
};
class Cclass_25_User {
private:
    Iclass_25* m_class { nullptr };
public:
    Cclass_25_User (Iclass_25* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_26 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_26 : public Iclass_26 {
public:
    Cclass_26 () = default;
    int func_a () override { return 27; }
    int func_b () override { return 29; }
};
class Cclass_26_User {
private:
    Iclass_26* m_class { nullptr };
public:
    Cclass_26_User (Iclass_26* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_27 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_27 : public Iclass_27 {
public:
    Cclass_27 () = default;
    int func_a () override { return 28; }
    int func_b () override { return 30; }
};
class Cclass_27_User {
private:
    Iclass_27* m_class { nullptr };
public:
    Cclass_27_User (Iclass_27* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_28 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_28 : public Iclass_28 {
public:
    Cclass_28 () = default;
    int func_a () override { return 29; }
    int func_b () override { return 31; }
};
class Cclass_28_User {
private:
    Iclass_28* m_class { nullptr };
public:
    Cclass_28_User (Iclass_28* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_29 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_29 : public Iclass_29 {
public:
    Cclass_29 () = default;
    int func_a () override { return 30; }
    int func_b () override { return 32; }
};
class Cclass_29_User {
private:
    Iclass_29* m_class { nullptr };
public:
    Cclass_29_User (Iclass_29* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_30 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_30 : public Iclass_30 {
public:
    Cclass_30 () = default;
    int func_a () override { return 31; }
    int func_b () override { return 33; }
};
class Cclass_30_User {
private:
    Iclass_30* m_class { nullptr };
public:
    Cclass_30_User (Iclass_30* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_31 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_31 : public Iclass_31 {
public:
    Cclass_31 () = default;
    int func_a () override { return 32; }
    int func_b () override { return 34; }
};
class Cclass_31_User {
private:
    Iclass_31* m_class { nullptr };
public:
    Cclass_31_User (Iclass_31* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_32 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_32 : public Iclass_32 {
public:
    Cclass_32 () = default;
    int func_a () override { return 33; }
    int func_b () override { return 35; }
};
class Cclass_32_User {
private:
    Iclass_32* m_class { nullptr };
public:
    Cclass_32_User (Iclass_32* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_33 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_33 : public Iclass_33 {
public:
    Cclass_33 () = default;
    int func_a () override { return 34; }
    int func_b () override { return 36; }
};
class Cclass_33_User {
private:
    Iclass_33* m_class { nullptr };
public:
    Cclass_33_User (Iclass_33* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_34 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_34 : public Iclass_34 {
public:
    Cclass_34 () = default;
    int func_a () override { return 35; }
    int func_b () override { return 37; }
};
class Cclass_34_User {
private:
    Iclass_34* m_class { nullptr };
public:
    Cclass_34_User (Iclass_34* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_35 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_35 : public Iclass_35 {
public:
    Cclass_35 () = default;
    int func_a () override { return 36; }
    int func_b () override { return 38; }
};
class Cclass_35_User {
private:
    Iclass_35* m_class { nullptr };
public:
    Cclass_35_User (Iclass_35* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_36 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_36 : public Iclass_36 {
public:
    Cclass_36 () = default;
    int func_a () override { return 37; }
    int func_b () override { return 39; }
};
class Cclass_36_User {
private:
    Iclass_36* m_class { nullptr };
public:
    Cclass_36_User (Iclass_36* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_37 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_37 : public Iclass_37 {
public:
    Cclass_37 () = default;
    int func_a () override { return 38; }
    int func_b () override { return 40; }
};
class Cclass_37_User {
private:
    Iclass_37* m_class { nullptr };
public:
    Cclass_37_User (Iclass_37* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_38 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_38 : public Iclass_38 {
public:
    Cclass_38 () = default;
    int func_a () override { return 39; }
    int func_b () override { return 41; }
};
class Cclass_38_User {
private:
    Iclass_38* m_class { nullptr };
public:
    Cclass_38_User (Iclass_38* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_39 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_39 : public Iclass_39 {
public:
    Cclass_39 () = default;
    int func_a () override { return 40; }
    int func_b () override { return 42; }
};
class Cclass_39_User {
private:
    Iclass_39* m_class { nullptr };
public:
    Cclass_39_User (Iclass_39* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_40 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_40 : public Iclass_40 {
public:
    Cclass_40 () = default;
    int func_a () override { return 41; }
    int func_b () override { return 43; }
};
class Cclass_40_User {
private:
    Iclass_40* m_class { nullptr };
public:
    Cclass_40_User (Iclass_40* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_41 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_41 : public Iclass_41 {
public:
    Cclass_41 () = default;
    int func_a () override { return 42; }
    int func_b () override { return 44; }
};
class Cclass_41_User {
private:
    Iclass_41* m_class { nullptr };
public:
    Cclass_41_User (Iclass_41* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_42 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_42 : public Iclass_42 {
public:
    Cclass_42 () = default;
    int func_a () override { return 43; }
    int func_b () override { return 45; }
};
class Cclass_42_User {
private:
    Iclass_42* m_class { nullptr };
public:
    Cclass_42_User (Iclass_42* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_43 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_43 : public Iclass_43 {
public:
    Cclass_43 () = default;
    int func_a () override { return 44; }
    int func_b () override { return 46; }
};
class Cclass_43_User {
private:
    Iclass_43* m_class { nullptr };
public:
    Cclass_43_User (Iclass_43* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_44 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_44 : public Iclass_44 {
public:
    Cclass_44 () = default;
    int func_a () override { return 45; }
    int func_b () override { return 47; }
};
class Cclass_44_User {
private:
    Iclass_44* m_class { nullptr };
public:
    Cclass_44_User (Iclass_44* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_45 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_45 : public Iclass_45 {
public:
    Cclass_45 () = default;
    int func_a () override { return 46; }
    int func_b () override { return 48; }
};
class Cclass_45_User {
private:
    Iclass_45* m_class { nullptr };
public:
    Cclass_45_User (Iclass_45* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_46 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_46 : public Iclass_46 {
public:
    Cclass_46 () = default;
    int func_a () override { return 47; }
    int func_b () override { return 49; }
};
class Cclass_46_User {
private:
    Iclass_46* m_class { nullptr };
public:
    Cclass_46_User (Iclass_46* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_47 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_47 : public Iclass_47 {
public:
    Cclass_47 () = default;
    int func_a () override { return 48; }
    int func_b () override { return 50; }
};
class Cclass_47_User {
private:
    Iclass_47* m_class { nullptr };
public:
    Cclass_47_User (Iclass_47* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_48 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_48 : public Iclass_48 {
public:
    Cclass_48 () = default;
    int func_a () override { return 49; }
    int func_b () override { return 51; }
};
class Cclass_48_User {
private:
    Iclass_48* m_class { nullptr };
public:
    Cclass_48_User (Iclass_48* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_49 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_49 : public Iclass_49 {
public:
    Cclass_49 () = default;
    int func_a () override { return 50; }
    int func_b () override { return 52; }
};
class Cclass_49_User {
private:
    Iclass_49* m_class { nullptr };
public:
    Cclass_49_User (Iclass_49* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_50 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_50 : public Iclass_50 {
public:
    Cclass_50 () = default;
    int func_a () override { return 51; }
    int func_b () override { return 53; }
};
class Cclass_50_User {
private:
    Iclass_50* m_class { nullptr };
public:
    Cclass_50_User (Iclass_50* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_51 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_51 : public Iclass_51 {
public:
    Cclass_51 () = default;
    int func_a () override { return 52; }
    int func_b () override { return 54; }
};
class Cclass_51_User {
private:
    Iclass_51* m_class { nullptr };
public:
    Cclass_51_User (Iclass_51* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_52 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_52 : public Iclass_52 {
public:
    Cclass_52 () = default;
    int func_a () override { return 53; }
    int func_b () override { return 55; }
};
class Cclass_52_User {
private:
    Iclass_52* m_class { nullptr };
public:
    Cclass_52_User (Iclass_52* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_53 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_53 : public Iclass_53 {
public:
    Cclass_53 () = default;
    int func_a () override { return 54; }
    int func_b () override { return 56; }
};
class Cclass_53_User {
private:
    Iclass_53* m_class { nullptr };
public:
    Cclass_53_User (Iclass_53* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_54 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_54 : public Iclass_54 {
public:
    Cclass_54 () = default;
    int func_a () override { return 55; }
    int func_b () override { return 57; }
};
class Cclass_54_User {
private:
    Iclass_54* m_class { nullptr };
public:
    Cclass_54_User (Iclass_54* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_55 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_55 : public Iclass_55 {
public:
    Cclass_55 () = default;
    int func_a () override { return 56; }
    int func_b () override { return 58; }
};
class Cclass_55_User {
private:
    Iclass_55* m_class { nullptr };
public:
    Cclass_55_User (Iclass_55* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_56 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_56 : public Iclass_56 {
public:
    Cclass_56 () = default;
    int func_a () override { return 57; }
    int func_b () override { return 59; }
};
class Cclass_56_User {
private:
    Iclass_56* m_class { nullptr };
public:
    Cclass_56_User (Iclass_56* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_57 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_57 : public Iclass_57 {
public:
    Cclass_57 () = default;
    int func_a () override { return 58; }
    int func_b () override { return 60; }
};
class Cclass_57_User {
private:
    Iclass_57* m_class { nullptr };
public:
    Cclass_57_User (Iclass_57* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_58 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_58 : public Iclass_58 {
public:
    Cclass_58 () = default;
    int func_a () override { return 59; }
    int func_b () override { return 61; }
};
class Cclass_58_User {
private:
    Iclass_58* m_class { nullptr };
public:
    Cclass_58_User (Iclass_58* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_59 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_59 : public Iclass_59 {
public:
    Cclass_59 () = default;
    int func_a () override { return 60; }
    int func_b () override { return 62; }
};
class Cclass_59_User {
private:
    Iclass_59* m_class { nullptr };
public:
    Cclass_59_User (Iclass_59* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_60 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_60 : public Iclass_60 {
public:
    Cclass_60 () = default;
    int func_a () override { return 61; }
    int func_b () override { return 63; }
};
class Cclass_60_User {
private:
    Iclass_60* m_class { nullptr };
public:
    Cclass_60_User (Iclass_60* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_61 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_61 : public Iclass_61 {
public:
    Cclass_61 () = default;
    int func_a () override { return 62; }
    int func_b () override { return 64; }
};
class Cclass_61_User {
private:
    Iclass_61* m_class { nullptr };
public:
    Cclass_61_User (Iclass_61* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_62 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_62 : public Iclass_62 {
public:
    Cclass_62 () = default;
    int func_a () override { return 63; }
    int func_b () override { return 65; }
};
class Cclass_62_User {
private:
    Iclass_62* m_class { nullptr };
public:
    Cclass_62_User (Iclass_62* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_63 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_63 : public Iclass_63 {
public:
    Cclass_63 () = default;
    int func_a () override { return 64; }
    int func_b () override { return 66; }
};
class Cclass_63_User {
private:
    Iclass_63* m_class { nullptr };
public:
    Cclass_63_User (Iclass_63* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_64 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_64 : public Iclass_64 {
public:
    Cclass_64 () = default;
    int func_a () override { return 65; }
    int func_b () override { return 67; }
};
class Cclass_64_User {
private:
    Iclass_64* m_class { nullptr };
public:
    Cclass_64_User (Iclass_64* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_65 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_65 : public Iclass_65 {
public:
    Cclass_65 () = default;
    int func_a () override { return 66; }
    int func_b () override { return 68; }
};
class Cclass_65_User {
private:
    Iclass_65* m_class { nullptr };
public:
    Cclass_65_User (Iclass_65* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_66 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_66 : public Iclass_66 {
public:
    Cclass_66 () = default;
    int func_a () override { return 67; }
    int func_b () override { return 69; }
};
class Cclass_66_User {
private:
    Iclass_66* m_class { nullptr };
public:
    Cclass_66_User (Iclass_66* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_67 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_67 : public Iclass_67 {
public:
    Cclass_67 () = default;
    int func_a () override { return 68; }
    int func_b () override { return 70; }
};
class Cclass_67_User {
private:
    Iclass_67* m_class { nullptr };
public:
    Cclass_67_User (Iclass_67* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_68 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_68 : public Iclass_68 {
public:
    Cclass_68 () = default;
    int func_a () override { return 69; }
    int func_b () override { return 71; }
};
class Cclass_68_User {
private:
    Iclass_68* m_class { nullptr };
public:
    Cclass_68_User (Iclass_68* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_69 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_69 : public Iclass_69 {
public:
    Cclass_69 () = default;
    int func_a () override { return 70; }
    int func_b () override { return 72; }
};
class Cclass_69_User {
private:
    Iclass_69* m_class { nullptr };
public:
    Cclass_69_User (Iclass_69* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_70 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_70 : public Iclass_70 {
public:
    Cclass_70 () = default;
    int func_a () override { return 71; }
    int func_b () override { return 73; }
};
class Cclass_70_User {
private:
    Iclass_70* m_class { nullptr };
public:
    Cclass_70_User (Iclass_70* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_71 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_71 : public Iclass_71 {
public:
    Cclass_71 () = default;
    int func_a () override { return 72; }
    int func_b () override { return 74; }
};
class Cclass_71_User {
private:
    Iclass_71* m_class { nullptr };
public:
    Cclass_71_User (Iclass_71* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_72 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_72 : public Iclass_72 {
public:
    Cclass_72 () = default;
    int func_a () override { return 73; }
    int func_b () override { return 75; }
};
class Cclass_72_User {
private:
    Iclass_72* m_class { nullptr };
public:
    Cclass_72_User (Iclass_72* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_73 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_73 : public Iclass_73 {
public:
    Cclass_73 () = default;
    int func_a () override { return 74; }
    int func_b () override { return 76; }
};
class Cclass_73_User {
private:
    Iclass_73* m_class { nullptr };
public:
    Cclass_73_User (Iclass_73* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_74 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_74 : public Iclass_74 {
public:
    Cclass_74 () = default;
    int func_a () override { return 75; }
    int func_b () override { return 77; }
};
class Cclass_74_User {
private:
    Iclass_74* m_class { nullptr };
public:
    Cclass_74_User (Iclass_74* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_75 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_75 : public Iclass_75 {
public:
    Cclass_75 () = default;
    int func_a () override { return 76; }
    int func_b () override { return 78; }
};
class Cclass_75_User {
private:
    Iclass_75* m_class { nullptr };
public:
    Cclass_75_User (Iclass_75* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_76 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_76 : public Iclass_76 {
public:
    Cclass_76 () = default;
    int func_a () override { return 77; }
    int func_b () override { return 79; }
};
class Cclass_76_User {
private:
    Iclass_76* m_class { nullptr };
public:
    Cclass_76_User (Iclass_76* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_77 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_77 : public Iclass_77 {
public:
    Cclass_77 () = default;
    int func_a () override { return 78; }
    int func_b () override { return 80; }
};
class Cclass_77_User {
private:
    Iclass_77* m_class { nullptr };
public:
    Cclass_77_User (Iclass_77* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_78 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_78 : public Iclass_78 {
public:
    Cclass_78 () = default;
    int func_a () override { return 79; }
    int func_b () override { return 81; }
};
class Cclass_78_User {
private:
    Iclass_78* m_class { nullptr };
public:
    Cclass_78_User (Iclass_78* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_79 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_79 : public Iclass_79 {
public:
    Cclass_79 () = default;
    int func_a () override { return 80; }
    int func_b () override { return 82; }
};
class Cclass_79_User {
private:
    Iclass_79* m_class { nullptr };
public:
    Cclass_79_User (Iclass_79* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_80 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_80 : public Iclass_80 {
public:
    Cclass_80 () = default;
    int func_a () override { return 81; }
    int func_b () override { return 83; }
};
class Cclass_80_User {
private:
    Iclass_80* m_class { nullptr };
public:
    Cclass_80_User (Iclass_80* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_81 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_81 : public Iclass_81 {
public:
    Cclass_81 () = default;
    int func_a () override { return 82; }
    int func_b () override { return 84; }
};
class Cclass_81_User {
private:
    Iclass_81* m_class { nullptr };
public:
    Cclass_81_User (Iclass_81* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_82 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_82 : public Iclass_82 {
public:
    Cclass_82 () = default;
    int func_a () override { return 83; }
    int func_b () override { return 85; }
};
class Cclass_82_User {
private:
    Iclass_82* m_class { nullptr };
public:
    Cclass_82_User (Iclass_82* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_83 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_83 : public Iclass_83 {
public:
    Cclass_83 () = default;
    int func_a () override { return 84; }
    int func_b () override { return 86; }
};
class Cclass_83_User {
private:
    Iclass_83* m_class { nullptr };
public:
    Cclass_83_User (Iclass_83* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_84 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_84 : public Iclass_84 {
public:
    Cclass_84 () = default;
    int func_a () override { return 85; }
    int func_b () override { return 87; }
};
class Cclass_84_User {
private:
    Iclass_84* m_class { nullptr };
public:
    Cclass_84_User (Iclass_84* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_85 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_85 : public Iclass_85 {
public:
    Cclass_85 () = default;
    int func_a () override { return 86; }
    int func_b () override { return 88; }
};
class Cclass_85_User {
private:
    Iclass_85* m_class { nullptr };
public:
    Cclass_85_User (Iclass_85* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_86 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_86 : public Iclass_86 {
public:
    Cclass_86 () = default;
    int func_a () override { return 87; }
    int func_b () override { return 89; }
};
class Cclass_86_User {
private:
    Iclass_86* m_class { nullptr };
public:
    Cclass_86_User (Iclass_86* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_87 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_87 : public Iclass_87 {
public:
    Cclass_87 () = default;
    int func_a () override { return 88; }
    int func_b () override { return 90; }
};
class Cclass_87_User {
private:
    Iclass_87* m_class { nullptr };
public:
    Cclass_87_User (Iclass_87* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_88 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_88 : public Iclass_88 {
public:
    Cclass_88 () = default;
    int func_a () override { return 89; }
    int func_b () override { return 91; }
};
class Cclass_88_User {
private:
    Iclass_88* m_class { nullptr };
public:
    Cclass_88_User (Iclass_88* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_89 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_89 : public Iclass_89 {
public:
    Cclass_89 () = default;
    int func_a () override { return 90; }
    int func_b () override { return 92; }
};
class Cclass_89_User {
private:
    Iclass_89* m_class { nullptr };
public:
    Cclass_89_User (Iclass_89* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_90 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_90 : public Iclass_90 {
public:
    Cclass_90 () = default;
    int func_a () override { return 91; }
    int func_b () override { return 93; }
};
class Cclass_90_User {
private:
    Iclass_90* m_class { nullptr };
public:
    Cclass_90_User (Iclass_90* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_91 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_91 : public Iclass_91 {
public:
    Cclass_91 () = default;
    int func_a () override { return 92; }
    int func_b () override { return 94; }
};
class Cclass_91_User {
private:
    Iclass_91* m_class { nullptr };
public:
    Cclass_91_User (Iclass_91* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_92 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_92 : public Iclass_92 {
public:
    Cclass_92 () = default;
    int func_a () override { return 93; }
    int func_b () override { return 95; }
};
class Cclass_92_User {
private:
    Iclass_92* m_class { nullptr };
public:
    Cclass_92_User (Iclass_92* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_93 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_93 : public Iclass_93 {
public:
    Cclass_93 () = default;
    int func_a () override { return 94; }
    int func_b () override { return 96; }
};
class Cclass_93_User {
private:
    Iclass_93* m_class { nullptr };
public:
    Cclass_93_User (Iclass_93* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_94 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_94 : public Iclass_94 {
public:
    Cclass_94 () = default;
    int func_a () override { return 95; }
    int func_b () override { return 97; }
};
class Cclass_94_User {
private:
    Iclass_94* m_class { nullptr };
public:
    Cclass_94_User (Iclass_94* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_95 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_95 : public Iclass_95 {
public:
    Cclass_95 () = default;
    int func_a () override { return 96; }
    int func_b () override { return 98; }
};
class Cclass_95_User {
private:
    Iclass_95* m_class { nullptr };
public:
    Cclass_95_User (Iclass_95* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_96 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_96 : public Iclass_96 {
public:
    Cclass_96 () = default;
    int func_a () override { return 97; }
    int func_b () override { return 99; }
};
class Cclass_96_User {
private:
    Iclass_96* m_class { nullptr };
public:
    Cclass_96_User (Iclass_96* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_97 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_97 : public Iclass_97 {
public:
    Cclass_97 () = default;
    int func_a () override { return 98; }
    int func_b () override { return 100; }
};
class Cclass_97_User {
private:
    Iclass_97* m_class { nullptr };
public:
    Cclass_97_User (Iclass_97* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_98 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_98 : public Iclass_98 {
public:
    Cclass_98 () = default;
    int func_a () override { return 99; }
    int func_b () override { return 101; }
};
class Cclass_98_User {
private:
    Iclass_98* m_class { nullptr };
public:
    Cclass_98_User (Iclass_98* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_99 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_99 : public Iclass_99 {
public:
    Cclass_99 () = default;
    int func_a () override { return 100; }
    int func_b () override { return 102; }
};
class Cclass_99_User {
private:
    Iclass_99* m_class { nullptr };
public:
    Cclass_99_User (Iclass_99* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_100 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_100 : public Iclass_100 {
public:
    Cclass_100 () = default;
    int func_a () override { return 101; }
    int func_b () override { return 103; }
};
class Cclass_100_User {
private:
    Iclass_100* m_class { nullptr };
public:
    Cclass_100_User (Iclass_100* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_101 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_101 : public Iclass_101 {
public:
    Cclass_101 () = default;
    int func_a () override { return 102; }
    int func_b () override { return 104; }
};
class Cclass_101_User {
private:
    Iclass_101* m_class { nullptr };
public:
    Cclass_101_User (Iclass_101* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_102 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_102 : public Iclass_102 {
public:
    Cclass_102 () = default;
    int func_a () override { return 103; }
    int func_b () override { return 105; }
};
class Cclass_102_User {
private:
    Iclass_102* m_class { nullptr };
public:
    Cclass_102_User (Iclass_102* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_103 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_103 : public Iclass_103 {
public:
    Cclass_103 () = default;
    int func_a () override { return 104; }
    int func_b () override { return 106; }
};
class Cclass_103_User {
private:
    Iclass_103* m_class { nullptr };
public:
    Cclass_103_User (Iclass_103* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_104 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_104 : public Iclass_104 {
public:
    Cclass_104 () = default;
    int func_a () override { return 105; }
    int func_b () override { return 107; }
};
class Cclass_104_User {
private:
    Iclass_104* m_class { nullptr };
public:
    Cclass_104_User (Iclass_104* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_105 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_105 : public Iclass_105 {
public:
    Cclass_105 () = default;
    int func_a () override { return 106; }
    int func_b () override { return 108; }
};
class Cclass_105_User {
private:
    Iclass_105* m_class { nullptr };
public:
    Cclass_105_User (Iclass_105* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_106 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_106 : public Iclass_106 {
public:
    Cclass_106 () = default;
    int func_a () override { return 107; }
    int func_b () override { return 109; }
};
class Cclass_106_User {
private:
    Iclass_106* m_class { nullptr };
public:
    Cclass_106_User (Iclass_106* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_107 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_107 : public Iclass_107 {
public:
    Cclass_107 () = default;
    int func_a () override { return 108; }
    int func_b () override { return 110; }
};
class Cclass_107_User {
private:
    Iclass_107* m_class { nullptr };
public:
    Cclass_107_User (Iclass_107* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_108 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_108 : public Iclass_108 {
public:
    Cclass_108 () = default;
    int func_a () override { return 109; }
    int func_b () override { return 111; }
};
class Cclass_108_User {
private:
    Iclass_108* m_class { nullptr };
public:
    Cclass_108_User (Iclass_108* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_109 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_109 : public Iclass_109 {
public:
    Cclass_109 () = default;
    int func_a () override { return 110; }
    int func_b () override { return 112; }
};
class Cclass_109_User {
private:
    Iclass_109* m_class { nullptr };
public:
    Cclass_109_User (Iclass_109* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_110 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_110 : public Iclass_110 {
public:
    Cclass_110 () = default;
    int func_a () override { return 111; }
    int func_b () override { return 113; }
};
class Cclass_110_User {
private:
    Iclass_110* m_class { nullptr };
public:
    Cclass_110_User (Iclass_110* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_111 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_111 : public Iclass_111 {
public:
    Cclass_111 () = default;
    int func_a () override { return 112; }
    int func_b () override { return 114; }
};
class Cclass_111_User {
private:
    Iclass_111* m_class { nullptr };
public:
    Cclass_111_User (Iclass_111* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_112 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_112 : public Iclass_112 {
public:
    Cclass_112 () = default;
    int func_a () override { return 113; }
    int func_b () override { return 115; }
};
class Cclass_112_User {
private:
    Iclass_112* m_class { nullptr };
public:
    Cclass_112_User (Iclass_112* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_113 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_113 : public Iclass_113 {
public:
    Cclass_113 () = default;
    int func_a () override { return 114; }
    int func_b () override { return 116; }
};
class Cclass_113_User {
private:
    Iclass_113* m_class { nullptr };
public:
    Cclass_113_User (Iclass_113* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_114 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_114 : public Iclass_114 {
public:
    Cclass_114 () = default;
    int func_a () override { return 115; }
    int func_b () override { return 117; }
};
class Cclass_114_User {
private:
    Iclass_114* m_class { nullptr };
public:
    Cclass_114_User (Iclass_114* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_115 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_115 : public Iclass_115 {
public:
    Cclass_115 () = default;
    int func_a () override { return 116; }
    int func_b () override { return 118; }
};
class Cclass_115_User {
private:
    Iclass_115* m_class { nullptr };
public:
    Cclass_115_User (Iclass_115* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_116 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_116 : public Iclass_116 {
public:
    Cclass_116 () = default;
    int func_a () override { return 117; }
    int func_b () override { return 119; }
};
class Cclass_116_User {
private:
    Iclass_116* m_class { nullptr };
public:
    Cclass_116_User (Iclass_116* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_117 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_117 : public Iclass_117 {
public:
    Cclass_117 () = default;
    int func_a () override { return 118; }
    int func_b () override { return 120; }
};
class Cclass_117_User {
private:
    Iclass_117* m_class { nullptr };
public:
    Cclass_117_User (Iclass_117* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_118 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_118 : public Iclass_118 {
public:
    Cclass_118 () = default;
    int func_a () override { return 119; }
    int func_b () override { return 121; }
};
class Cclass_118_User {
private:
    Iclass_118* m_class { nullptr };
public:
    Cclass_118_User (Iclass_118* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_119 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_119 : public Iclass_119 {
public:
    Cclass_119 () = default;
    int func_a () override { return 120; }
    int func_b () override { return 122; }
};
class Cclass_119_User {
private:
    Iclass_119* m_class { nullptr };
public:
    Cclass_119_User (Iclass_119* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_120 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_120 : public Iclass_120 {
public:
    Cclass_120 () = default;
    int func_a () override { return 121; }
    int func_b () override { return 123; }
};
class Cclass_120_User {
private:
    Iclass_120* m_class { nullptr };
public:
    Cclass_120_User (Iclass_120* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_121 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_121 : public Iclass_121 {
public:
    Cclass_121 () = default;
    int func_a () override { return 122; }
    int func_b () override { return 124; }
};
class Cclass_121_User {
private:
    Iclass_121* m_class { nullptr };
public:
    Cclass_121_User (Iclass_121* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_122 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_122 : public Iclass_122 {
public:
    Cclass_122 () = default;
    int func_a () override { return 123; }
    int func_b () override { return 125; }
};
class Cclass_122_User {
private:
    Iclass_122* m_class { nullptr };
public:
    Cclass_122_User (Iclass_122* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_123 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_123 : public Iclass_123 {
public:
    Cclass_123 () = default;
    int func_a () override { return 124; }
    int func_b () override { return 126; }
};
class Cclass_123_User {
private:
    Iclass_123* m_class { nullptr };
public:
    Cclass_123_User (Iclass_123* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_124 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_124 : public Iclass_124 {
public:
    Cclass_124 () = default;
    int func_a () override { return 125; }
    int func_b () override { return 127; }
};
class Cclass_124_User {
private:
    Iclass_124* m_class { nullptr };
public:
    Cclass_124_User (Iclass_124* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_125 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_125 : public Iclass_125 {
public:
    Cclass_125 () = default;
    int func_a () override { return 126; }
    int func_b () override { return 128; }
};
class Cclass_125_User {
private:
    Iclass_125* m_class { nullptr };
public:
    Cclass_125_User (Iclass_125* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_126 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_126 : public Iclass_126 {
public:
    Cclass_126 () = default;
    int func_a () override { return 127; }
    int func_b () override { return 129; }
};
class Cclass_126_User {
private:
    Iclass_126* m_class { nullptr };
public:
    Cclass_126_User (Iclass_126* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_127 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_127 : public Iclass_127 {
public:
    Cclass_127 () = default;
    int func_a () override { return 128; }
    int func_b () override { return 130; }
};
class Cclass_127_User {
private:
    Iclass_127* m_class { nullptr };
public:
    Cclass_127_User (Iclass_127* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_128 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_128 : public Iclass_128 {
public:
    Cclass_128 () = default;
    int func_a () override { return 129; }
    int func_b () override { return 131; }
};
class Cclass_128_User {
private:
    Iclass_128* m_class { nullptr };
public:
    Cclass_128_User (Iclass_128* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_129 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_129 : public Iclass_129 {
public:
    Cclass_129 () = default;
    int func_a () override { return 130; }
    int func_b () override { return 132; }
};
class Cclass_129_User {
private:
    Iclass_129* m_class { nullptr };
public:
    Cclass_129_User (Iclass_129* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_130 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_130 : public Iclass_130 {
public:
    Cclass_130 () = default;
    int func_a () override { return 131; }
    int func_b () override { return 133; }
};
class Cclass_130_User {
private:
    Iclass_130* m_class { nullptr };
public:
    Cclass_130_User (Iclass_130* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_131 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_131 : public Iclass_131 {
public:
    Cclass_131 () = default;
    int func_a () override { return 132; }
    int func_b () override { return 134; }
};
class Cclass_131_User {
private:
    Iclass_131* m_class { nullptr };
public:
    Cclass_131_User (Iclass_131* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_132 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_132 : public Iclass_132 {
public:
    Cclass_132 () = default;
    int func_a () override { return 133; }
    int func_b () override { return 135; }
};
class Cclass_132_User {
private:
    Iclass_132* m_class { nullptr };
public:
    Cclass_132_User (Iclass_132* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_133 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_133 : public Iclass_133 {
public:
    Cclass_133 () = default;
    int func_a () override { return 134; }
    int func_b () override { return 136; }
};
class Cclass_133_User {
private:
    Iclass_133* m_class { nullptr };
public:
    Cclass_133_User (Iclass_133* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_134 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_134 : public Iclass_134 {
public:
    Cclass_134 () = default;
    int func_a () override { return 135; }
    int func_b () override { return 137; }
};
class Cclass_134_User {
private:
    Iclass_134* m_class { nullptr };
public:
    Cclass_134_User (Iclass_134* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_135 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_135 : public Iclass_135 {
public:
    Cclass_135 () = default;
    int func_a () override { return 136; }
    int func_b () override { return 138; }
};
class Cclass_135_User {
private:
    Iclass_135* m_class { nullptr };
public:
    Cclass_135_User (Iclass_135* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_136 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_136 : public Iclass_136 {
public:
    Cclass_136 () = default;
    int func_a () override { return 137; }
    int func_b () override { return 139; }
};
class Cclass_136_User {
private:
    Iclass_136* m_class { nullptr };
public:
    Cclass_136_User (Iclass_136* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_137 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_137 : public Iclass_137 {
public:
    Cclass_137 () = default;
    int func_a () override { return 138; }
    int func_b () override { return 140; }
};
class Cclass_137_User {
private:
    Iclass_137* m_class { nullptr };
public:
    Cclass_137_User (Iclass_137* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_138 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_138 : public Iclass_138 {
public:
    Cclass_138 () = default;
    int func_a () override { return 139; }
    int func_b () override { return 141; }
};
class Cclass_138_User {
private:
    Iclass_138* m_class { nullptr };
public:
    Cclass_138_User (Iclass_138* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_139 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_139 : public Iclass_139 {
public:
    Cclass_139 () = default;
    int func_a () override { return 140; }
    int func_b () override { return 142; }
};
class Cclass_139_User {
private:
    Iclass_139* m_class { nullptr };
public:
    Cclass_139_User (Iclass_139* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_140 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_140 : public Iclass_140 {
public:
    Cclass_140 () = default;
    int func_a () override { return 141; }
    int func_b () override { return 143; }
};
class Cclass_140_User {
private:
    Iclass_140* m_class { nullptr };
public:
    Cclass_140_User (Iclass_140* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_141 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_141 : public Iclass_141 {
public:
    Cclass_141 () = default;
    int func_a () override { return 142; }
    int func_b () override { return 144; }
};
class Cclass_141_User {
private:
    Iclass_141* m_class { nullptr };
public:
    Cclass_141_User (Iclass_141* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_142 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_142 : public Iclass_142 {
public:
    Cclass_142 () = default;
    int func_a () override { return 143; }
    int func_b () override { return 145; }
};
class Cclass_142_User {
private:
    Iclass_142* m_class { nullptr };
public:
    Cclass_142_User (Iclass_142* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_143 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_143 : public Iclass_143 {
public:
    Cclass_143 () = default;
    int func_a () override { return 144; }
    int func_b () override { return 146; }
};
class Cclass_143_User {
private:
    Iclass_143* m_class { nullptr };
public:
    Cclass_143_User (Iclass_143* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_144 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_144 : public Iclass_144 {
public:
    Cclass_144 () = default;
    int func_a () override { return 145; }
    int func_b () override { return 147; }
};
class Cclass_144_User {
private:
    Iclass_144* m_class { nullptr };
public:
    Cclass_144_User (Iclass_144* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_145 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_145 : public Iclass_145 {
public:
    Cclass_145 () = default;
    int func_a () override { return 146; }
    int func_b () override { return 148; }
};
class Cclass_145_User {
private:
    Iclass_145* m_class { nullptr };
public:
    Cclass_145_User (Iclass_145* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_146 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_146 : public Iclass_146 {
public:
    Cclass_146 () = default;
    int func_a () override { return 147; }
    int func_b () override { return 149; }
};
class Cclass_146_User {
private:
    Iclass_146* m_class { nullptr };
public:
    Cclass_146_User (Iclass_146* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_147 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_147 : public Iclass_147 {
public:
    Cclass_147 () = default;
    int func_a () override { return 148; }
    int func_b () override { return 150; }
};
class Cclass_147_User {
private:
    Iclass_147* m_class { nullptr };
public:
    Cclass_147_User (Iclass_147* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_148 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_148 : public Iclass_148 {
public:
    Cclass_148 () = default;
    int func_a () override { return 149; }
    int func_b () override { return 151; }
};
class Cclass_148_User {
private:
    Iclass_148* m_class { nullptr };
public:
    Cclass_148_User (Iclass_148* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_149 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_149 : public Iclass_149 {
public:
    Cclass_149 () = default;
    int func_a () override { return 150; }
    int func_b () override { return 152; }
};
class Cclass_149_User {
private:
    Iclass_149* m_class { nullptr };
public:
    Cclass_149_User (Iclass_149* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_150 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_150 : public Iclass_150 {
public:
    Cclass_150 () = default;
    int func_a () override { return 151; }
    int func_b () override { return 153; }
};
class Cclass_150_User {
private:
    Iclass_150* m_class { nullptr };
public:
    Cclass_150_User (Iclass_150* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_151 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_151 : public Iclass_151 {
public:
    Cclass_151 () = default;
    int func_a () override { return 152; }
    int func_b () override { return 154; }
};
class Cclass_151_User {
private:
    Iclass_151* m_class { nullptr };
public:
    Cclass_151_User (Iclass_151* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_152 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_152 : public Iclass_152 {
public:
    Cclass_152 () = default;
    int func_a () override { return 153; }
    int func_b () override { return 155; }
};
class Cclass_152_User {
private:
    Iclass_152* m_class { nullptr };
public:
    Cclass_152_User (Iclass_152* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_153 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_153 : public Iclass_153 {
public:
    Cclass_153 () = default;
    int func_a () override { return 154; }
    int func_b () override { return 156; }
};
class Cclass_153_User {
private:
    Iclass_153* m_class { nullptr };
public:
    Cclass_153_User (Iclass_153* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_154 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_154 : public Iclass_154 {
public:
    Cclass_154 () = default;
    int func_a () override { return 155; }
    int func_b () override { return 157; }
};
class Cclass_154_User {
private:
    Iclass_154* m_class { nullptr };
public:
    Cclass_154_User (Iclass_154* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_155 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_155 : public Iclass_155 {
public:
    Cclass_155 () = default;
    int func_a () override { return 156; }
    int func_b () override { return 158; }
};
class Cclass_155_User {
private:
    Iclass_155* m_class { nullptr };
public:
    Cclass_155_User (Iclass_155* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_156 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_156 : public Iclass_156 {
public:
    Cclass_156 () = default;
    int func_a () override { return 157; }
    int func_b () override { return 159; }
};
class Cclass_156_User {
private:
    Iclass_156* m_class { nullptr };
public:
    Cclass_156_User (Iclass_156* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_157 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_157 : public Iclass_157 {
public:
    Cclass_157 () = default;
    int func_a () override { return 158; }
    int func_b () override { return 160; }
};
class Cclass_157_User {
private:
    Iclass_157* m_class { nullptr };
public:
    Cclass_157_User (Iclass_157* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_158 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_158 : public Iclass_158 {
public:
    Cclass_158 () = default;
    int func_a () override { return 159; }
    int func_b () override { return 161; }
};
class Cclass_158_User {
private:
    Iclass_158* m_class { nullptr };
public:
    Cclass_158_User (Iclass_158* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_159 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_159 : public Iclass_159 {
public:
    Cclass_159 () = default;
    int func_a () override { return 160; }
    int func_b () override { return 162; }
};
class Cclass_159_User {
private:
    Iclass_159* m_class { nullptr };
public:
    Cclass_159_User (Iclass_159* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_160 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_160 : public Iclass_160 {
public:
    Cclass_160 () = default;
    int func_a () override { return 161; }
    int func_b () override { return 163; }
};
class Cclass_160_User {
private:
    Iclass_160* m_class { nullptr };
public:
    Cclass_160_User (Iclass_160* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_161 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_161 : public Iclass_161 {
public:
    Cclass_161 () = default;
    int func_a () override { return 162; }
    int func_b () override { return 164; }
};
class Cclass_161_User {
private:
    Iclass_161* m_class { nullptr };
public:
    Cclass_161_User (Iclass_161* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_162 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_162 : public Iclass_162 {
public:
    Cclass_162 () = default;
    int func_a () override { return 163; }
    int func_b () override { return 165; }
};
class Cclass_162_User {
private:
    Iclass_162* m_class { nullptr };
public:
    Cclass_162_User (Iclass_162* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_163 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_163 : public Iclass_163 {
public:
    Cclass_163 () = default;
    int func_a () override { return 164; }
    int func_b () override { return 166; }
};
class Cclass_163_User {
private:
    Iclass_163* m_class { nullptr };
public:
    Cclass_163_User (Iclass_163* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_164 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_164 : public Iclass_164 {
public:
    Cclass_164 () = default;
    int func_a () override { return 165; }
    int func_b () override { return 167; }
};
class Cclass_164_User {
private:
    Iclass_164* m_class { nullptr };
public:
    Cclass_164_User (Iclass_164* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_165 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_165 : public Iclass_165 {
public:
    Cclass_165 () = default;
    int func_a () override { return 166; }
    int func_b () override { return 168; }
};
class Cclass_165_User {
private:
    Iclass_165* m_class { nullptr };
public:
    Cclass_165_User (Iclass_165* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_166 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_166 : public Iclass_166 {
public:
    Cclass_166 () = default;
    int func_a () override { return 167; }
    int func_b () override { return 169; }
};
class Cclass_166_User {
private:
    Iclass_166* m_class { nullptr };
public:
    Cclass_166_User (Iclass_166* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_167 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_167 : public Iclass_167 {
public:
    Cclass_167 () = default;
    int func_a () override { return 168; }
    int func_b () override { return 170; }
};
class Cclass_167_User {
private:
    Iclass_167* m_class { nullptr };
public:
    Cclass_167_User (Iclass_167* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_168 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_168 : public Iclass_168 {
public:
    Cclass_168 () = default;
    int func_a () override { return 169; }
    int func_b () override { return 171; }
};
class Cclass_168_User {
private:
    Iclass_168* m_class { nullptr };
public:
    Cclass_168_User (Iclass_168* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_169 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_169 : public Iclass_169 {
public:
    Cclass_169 () = default;
    int func_a () override { return 170; }
    int func_b () override { return 172; }
};
class Cclass_169_User {
private:
    Iclass_169* m_class { nullptr };
public:
    Cclass_169_User (Iclass_169* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_170 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_170 : public Iclass_170 {
public:
    Cclass_170 () = default;
    int func_a () override { return 171; }
    int func_b () override { return 173; }
};
class Cclass_170_User {
private:
    Iclass_170* m_class { nullptr };
public:
    Cclass_170_User (Iclass_170* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_171 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_171 : public Iclass_171 {
public:
    Cclass_171 () = default;
    int func_a () override { return 172; }
    int func_b () override { return 174; }
};
class Cclass_171_User {
private:
    Iclass_171* m_class { nullptr };
public:
    Cclass_171_User (Iclass_171* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_172 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_172 : public Iclass_172 {
public:
    Cclass_172 () = default;
    int func_a () override { return 173; }
    int func_b () override { return 175; }
};
class Cclass_172_User {
private:
    Iclass_172* m_class { nullptr };
public:
    Cclass_172_User (Iclass_172* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_173 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_173 : public Iclass_173 {
public:
    Cclass_173 () = default;
    int func_a () override { return 174; }
    int func_b () override { return 176; }
};
class Cclass_173_User {
private:
    Iclass_173* m_class { nullptr };
public:
    Cclass_173_User (Iclass_173* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_174 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_174 : public Iclass_174 {
public:
    Cclass_174 () = default;
    int func_a () override { return 175; }
    int func_b () override { return 177; }
};
class Cclass_174_User {
private:
    Iclass_174* m_class { nullptr };
public:
    Cclass_174_User (Iclass_174* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_175 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_175 : public Iclass_175 {
public:
    Cclass_175 () = default;
    int func_a () override { return 176; }
    int func_b () override { return 178; }
};
class Cclass_175_User {
private:
    Iclass_175* m_class { nullptr };
public:
    Cclass_175_User (Iclass_175* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_176 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_176 : public Iclass_176 {
public:
    Cclass_176 () = default;
    int func_a () override { return 177; }
    int func_b () override { return 179; }
};
class Cclass_176_User {
private:
    Iclass_176* m_class { nullptr };
public:
    Cclass_176_User (Iclass_176* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_177 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_177 : public Iclass_177 {
public:
    Cclass_177 () = default;
    int func_a () override { return 178; }
    int func_b () override { return 180; }
};
class Cclass_177_User {
private:
    Iclass_177* m_class { nullptr };
public:
    Cclass_177_User (Iclass_177* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_178 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_178 : public Iclass_178 {
public:
    Cclass_178 () = default;
    int func_a () override { return 179; }
    int func_b () override { return 181; }
};
class Cclass_178_User {
private:
    Iclass_178* m_class { nullptr };
public:
    Cclass_178_User (Iclass_178* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_179 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_179 : public Iclass_179 {
public:
    Cclass_179 () = default;
    int func_a () override { return 180; }
    int func_b () override { return 182; }
};
class Cclass_179_User {
private:
    Iclass_179* m_class { nullptr };
public:
    Cclass_179_User (Iclass_179* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_180 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_180 : public Iclass_180 {
public:
    Cclass_180 () = default;
    int func_a () override { return 181; }
    int func_b () override { return 183; }
};
class Cclass_180_User {
private:
    Iclass_180* m_class { nullptr };
public:
    Cclass_180_User (Iclass_180* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_181 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_181 : public Iclass_181 {
public:
    Cclass_181 () = default;
    int func_a () override { return 182; }
    int func_b () override { return 184; }
};
class Cclass_181_User {
private:
    Iclass_181* m_class { nullptr };
public:
    Cclass_181_User (Iclass_181* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_182 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_182 : public Iclass_182 {
public:
    Cclass_182 () = default;
    int func_a () override { return 183; }
    int func_b () override { return 185; }
};
class Cclass_182_User {
private:
    Iclass_182* m_class { nullptr };
public:
    Cclass_182_User (Iclass_182* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_183 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_183 : public Iclass_183 {
public:
    Cclass_183 () = default;
    int func_a () override { return 184; }
    int func_b () override { return 186; }
};
class Cclass_183_User {
private:
    Iclass_183* m_class { nullptr };
public:
    Cclass_183_User (Iclass_183* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_184 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_184 : public Iclass_184 {
public:
    Cclass_184 () = default;
    int func_a () override { return 185; }
    int func_b () override { return 187; }
};
class Cclass_184_User {
private:
    Iclass_184* m_class { nullptr };
public:
    Cclass_184_User (Iclass_184* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_185 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_185 : public Iclass_185 {
public:
    Cclass_185 () = default;
    int func_a () override { return 186; }
    int func_b () override { return 188; }
};
class Cclass_185_User {
private:
    Iclass_185* m_class { nullptr };
public:
    Cclass_185_User (Iclass_185* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_186 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_186 : public Iclass_186 {
public:
    Cclass_186 () = default;
    int func_a () override { return 187; }
    int func_b () override { return 189; }
};
class Cclass_186_User {
private:
    Iclass_186* m_class { nullptr };
public:
    Cclass_186_User (Iclass_186* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_187 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_187 : public Iclass_187 {
public:
    Cclass_187 () = default;
    int func_a () override { return 188; }
    int func_b () override { return 190; }
};
class Cclass_187_User {
private:
    Iclass_187* m_class { nullptr };
public:
    Cclass_187_User (Iclass_187* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_188 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_188 : public Iclass_188 {
public:
    Cclass_188 () = default;
    int func_a () override { return 189; }
    int func_b () override { return 191; }
};
class Cclass_188_User {
private:
    Iclass_188* m_class { nullptr };
public:
    Cclass_188_User (Iclass_188* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_189 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_189 : public Iclass_189 {
public:
    Cclass_189 () = default;
    int func_a () override { return 190; }
    int func_b () override { return 192; }
};
class Cclass_189_User {
private:
    Iclass_189* m_class { nullptr };
public:
    Cclass_189_User (Iclass_189* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_190 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_190 : public Iclass_190 {
public:
    Cclass_190 () = default;
    int func_a () override { return 191; }
    int func_b () override { return 193; }
};
class Cclass_190_User {
private:
    Iclass_190* m_class { nullptr };
public:
    Cclass_190_User (Iclass_190* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_191 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_191 : public Iclass_191 {
public:
    Cclass_191 () = default;
    int func_a () override { return 192; }
    int func_b () override { return 194; }
};
class Cclass_191_User {
private:
    Iclass_191* m_class { nullptr };
public:
    Cclass_191_User (Iclass_191* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_192 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_192 : public Iclass_192 {
public:
    Cclass_192 () = default;
    int func_a () override { return 193; }
    int func_b () override { return 195; }
};
class Cclass_192_User {
private:
    Iclass_192* m_class { nullptr };
public:
    Cclass_192_User (Iclass_192* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_193 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_193 : public Iclass_193 {
public:
    Cclass_193 () = default;
    int func_a () override { return 194; }
    int func_b () override { return 196; }
};
class Cclass_193_User {
private:
    Iclass_193* m_class { nullptr };
public:
    Cclass_193_User (Iclass_193* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_194 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_194 : public Iclass_194 {
public:
    Cclass_194 () = default;
    int func_a () override { return 195; }
    int func_b () override { return 197; }
};
class Cclass_194_User {
private:
    Iclass_194* m_class { nullptr };
public:
    Cclass_194_User (Iclass_194* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_195 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_195 : public Iclass_195 {
public:
    Cclass_195 () = default;
    int func_a () override { return 196; }
    int func_b () override { return 198; }
};
class Cclass_195_User {
private:
    Iclass_195* m_class { nullptr };
public:
    Cclass_195_User (Iclass_195* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_196 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_196 : public Iclass_196 {
public:
    Cclass_196 () = default;
    int func_a () override { return 197; }
    int func_b () override { return 199; }
};
class Cclass_196_User {
private:
    Iclass_196* m_class { nullptr };
public:
    Cclass_196_User (Iclass_196* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_197 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_197 : public Iclass_197 {
public:
    Cclass_197 () = default;
    int func_a () override { return 198; }
    int func_b () override { return 200; }
};
class Cclass_197_User {
private:
    Iclass_197* m_class { nullptr };
public:
    Cclass_197_User (Iclass_197* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_198 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_198 : public Iclass_198 {
public:
    Cclass_198 () = default;
    int func_a () override { return 199; }
    int func_b () override { return 201; }
};
class Cclass_198_User {
private:
    Iclass_198* m_class { nullptr };
public:
    Cclass_198_User (Iclass_198* _class) : m_class(_class) {}
    int use_func_a () {
        return m_class->func_a();
    }
    int use_func_b () {
        return m_class->func_b();
    }
};
class Iclass_199 {
public:
    virtual int func_a () = 0;
    virtual int func_b () = 0;
};
class Cclass_199 : public Iclass_199 {
public:
    Cclass_199 () = default;
    int func_a () override { return 200; }
    int func_b () override { return 202; }
};
class Cclass_199_User {
private:
    Iclass_199* m_class { nullptr };
public:
    Cclass_199_User (Iclass_199* _class) : m_class(_class) {}
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