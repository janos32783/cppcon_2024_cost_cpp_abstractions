#include <cstdint>

template <std::uint32_t address>
class CRegister {
public:
    void set (std::uint32_t val) const {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = val;
    }

    std::uint32_t get () const {
        return *(reinterpret_cast<volatile std::uint32_t *>(address));
    }

    void set (std::uint32_t value, std::uint32_t bitmask) const {
        std::uint32_t tmp = this->get();
        tmp &= ~bitmask;
        tmp |= value;
        this->set(tmp);
    }

    void set_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = *(reinterpret_cast<volatile std::uint32_t *>(address)) | bitmask;
    }

    void clear_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(address)) = *(reinterpret_cast<volatile std::uint32_t *>(address)) & ~bitmask;
    }

    bool is_set (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask) == bitmask;
    }

    bool is_cleared (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(address)) & bitmask) == 0;
    }

    std::uint32_t get_bits (std::uint32_t bitmask) {
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
class CREG_0 {
private:
    static inline const CRegister<0x48000000UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_75 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_1 {
private:
    static inline const CRegister<0x48000004UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_88 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_2 {
private:
    static inline const CRegister<0x48000008UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_95 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_3 {
private:
    static inline const CRegister<0x4800000cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_14 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_4 {
private:
    static inline const CRegister<0x48000010UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_65 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_5 {
private:
    static inline const CRegister<0x48000014UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_87 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_6 {
private:
    static inline const CRegister<0x48000018UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_85 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_7 {
private:
    static inline const CRegister<0x4800001cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_13 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_8 {
private:
    static inline const CRegister<0x48000020UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_76 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_9 {
private:
    static inline const CRegister<0x48000024UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_47 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_10 {
private:
    static inline const CRegister<0x48000028UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_29 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_11 {
private:
    static inline const CRegister<0x4800002cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_71 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_12 {
private:
    static inline const CRegister<0x48000030UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_81 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_13 {
private:
    static inline const CRegister<0x48000034UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_88 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_14 {
private:
    static inline const CRegister<0x48000038UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_47 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_15 {
private:
    static inline const CRegister<0x4800003cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_2 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_16 {
private:
    static inline const CRegister<0x48000040UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_22 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_17 {
private:
    static inline const CRegister<0x48000044UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_45 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_18 {
private:
    static inline const CRegister<0x48000048UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_39 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_19 {
private:
    static inline const CRegister<0x4800004cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_32 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_20 {
private:
    static inline const CRegister<0x48000050UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_95 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_21 {
private:
    static inline const CRegister<0x48000054UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_99 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_22 {
private:
    static inline const CRegister<0x48000058UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_15 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_23 {
private:
    static inline const CRegister<0x4800005cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_23 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_24 {
private:
    static inline const CRegister<0x48000060UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_38 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_25 {
private:
    static inline const CRegister<0x48000064UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_22 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_26 {
private:
    static inline const CRegister<0x48000068UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_52 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_27 {
private:
    static inline const CRegister<0x4800006cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_5 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_28 {
private:
    static inline const CRegister<0x48000070UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_29 {
private:
    static inline const CRegister<0x48000074UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_85 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_30 {
private:
    static inline const CRegister<0x48000078UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_71 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_31 {
private:
    static inline const CRegister<0x4800007cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_38 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_32 {
private:
    static inline const CRegister<0x48000080UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_55 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_33 {
private:
    static inline const CRegister<0x48000084UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_88 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_34 {
private:
    static inline const CRegister<0x48000088UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_47 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_35 {
private:
    static inline const CRegister<0x4800008cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_53 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_36 {
private:
    static inline const CRegister<0x48000090UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_95 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_37 {
private:
    static inline const CRegister<0x48000094UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_71 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_38 {
private:
    static inline const CRegister<0x48000098UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_83 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_39 {
private:
    static inline const CRegister<0x4800009cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_21 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_40 {
private:
    static inline const CRegister<0x480000a0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_41 {
private:
    static inline const CRegister<0x480000a4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_56 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_42 {
private:
    static inline const CRegister<0x480000a8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_94 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_43 {
private:
    static inline const CRegister<0x480000acUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_55 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_44 {
private:
    static inline const CRegister<0x480000b0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_28 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_45 {
private:
    static inline const CRegister<0x480000b4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_46 {
private:
    static inline const CRegister<0x480000b8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_36 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_47 {
private:
    static inline const CRegister<0x480000bcUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_74 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_48 {
private:
    static inline const CRegister<0x480000c0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_84 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_49 {
private:
    static inline const CRegister<0x480000c4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_25 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_50 {
private:
    static inline const CRegister<0x480000c8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_32 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_51 {
private:
    static inline const CRegister<0x480000ccUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_60 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_52 {
private:
    static inline const CRegister<0x480000d0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_72 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_53 {
private:
    static inline const CRegister<0x480000d4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_57 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_54 {
private:
    static inline const CRegister<0x480000d8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_55 {
private:
    static inline const CRegister<0x480000dcUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_23 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_56 {
private:
    static inline const CRegister<0x480000e0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_63 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_57 {
private:
    static inline const CRegister<0x480000e4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_5 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_58 {
private:
    static inline const CRegister<0x480000e8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_1 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_59 {
private:
    static inline const CRegister<0x480000ecUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_26 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_60 {
private:
    static inline const CRegister<0x480000f0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_87 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_61 {
private:
    static inline const CRegister<0x480000f4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_94 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_62 {
private:
    static inline const CRegister<0x480000f8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_23 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_63 {
private:
    static inline const CRegister<0x480000fcUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_21 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_64 {
private:
    static inline const CRegister<0x48000100UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_85 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_65 {
private:
    static inline const CRegister<0x48000104UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_80 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_66 {
private:
    static inline const CRegister<0x48000108UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_13 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_67 {
private:
    static inline const CRegister<0x4800010cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_82 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_68 {
private:
    static inline const CRegister<0x48000110UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_82 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_69 {
private:
    static inline const CRegister<0x48000114UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_99 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_70 {
private:
    static inline const CRegister<0x48000118UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_67 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_71 {
private:
    static inline const CRegister<0x4800011cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_74 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_72 {
private:
    static inline const CRegister<0x48000120UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_31 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_73 {
private:
    static inline const CRegister<0x48000124UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_91 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_74 {
private:
    static inline const CRegister<0x48000128UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_47 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_75 {
private:
    static inline const CRegister<0x4800012cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_46 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_76 {
private:
    static inline const CRegister<0x48000130UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_65 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_77 {
private:
    static inline const CRegister<0x48000134UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_43 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_78 {
private:
    static inline const CRegister<0x48000138UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_30 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_79 {
private:
    static inline const CRegister<0x4800013cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_27 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_80 {
private:
    static inline const CRegister<0x48000140UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_72 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_81 {
private:
    static inline const CRegister<0x48000144UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_1 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_82 {
private:
    static inline const CRegister<0x48000148UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_30 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_83 {
private:
    static inline const CRegister<0x4800014cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_70 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_84 {
private:
    static inline const CRegister<0x48000150UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_79 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_85 {
private:
    static inline const CRegister<0x48000154UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_69 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_86 {
private:
    static inline const CRegister<0x48000158UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_44 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_87 {
private:
    static inline const CRegister<0x4800015cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_15 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_88 {
private:
    static inline const CRegister<0x48000160UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_78 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_89 {
private:
    static inline const CRegister<0x48000164UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_90 {
private:
    static inline const CRegister<0x48000168UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_20 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_91 {
private:
    static inline const CRegister<0x4800016cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_4 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_92 {
private:
    static inline const CRegister<0x48000170UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_32 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_93 {
private:
    static inline const CRegister<0x48000174UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_94 {
private:
    static inline const CRegister<0x48000178UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_18 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_95 {
private:
    static inline const CRegister<0x4800017cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_64 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_96 {
private:
    static inline const CRegister<0x48000180UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_88 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_97 {
private:
    static inline const CRegister<0x48000184UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_75 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_98 {
private:
    static inline const CRegister<0x48000188UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_17 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_99 {
private:
    static inline const CRegister<0x4800018cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_51 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_100 {
private:
    static inline const CRegister<0x48000190UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_12 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_101 {
private:
    static inline const CRegister<0x48000194UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_38 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_102 {
private:
    static inline const CRegister<0x48000198UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_2 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_103 {
private:
    static inline const CRegister<0x4800019cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_54 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_104 {
private:
    static inline const CRegister<0x480001a0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_24 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_105 {
private:
    static inline const CRegister<0x480001a4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_54 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_106 {
private:
    static inline const CRegister<0x480001a8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_58 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_107 {
private:
    static inline const CRegister<0x480001acUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_3 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_108 {
private:
    static inline const CRegister<0x480001b0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_58 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_109 {
private:
    static inline const CRegister<0x480001b4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_58 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_110 {
private:
    static inline const CRegister<0x480001b8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_21 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_111 {
private:
    static inline const CRegister<0x480001bcUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_77 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_112 {
private:
    static inline const CRegister<0x480001c0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_67 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_113 {
private:
    static inline const CRegister<0x480001c4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_50 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_114 {
private:
    static inline const CRegister<0x480001c8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_7 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_115 {
private:
    static inline const CRegister<0x480001ccUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_65 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_116 {
private:
    static inline const CRegister<0x480001d0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_27 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_117 {
private:
    static inline const CRegister<0x480001d4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_84 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_118 {
private:
    static inline const CRegister<0x480001d8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_73 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_119 {
private:
    static inline const CRegister<0x480001dcUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_71 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_120 {
private:
    static inline const CRegister<0x480001e0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_121 {
private:
    static inline const CRegister<0x480001e4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_10 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_122 {
private:
    static inline const CRegister<0x480001e8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_49 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_123 {
private:
    static inline const CRegister<0x480001ecUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_55 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_124 {
private:
    static inline const CRegister<0x480001f0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_95 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_125 {
private:
    static inline const CRegister<0x480001f4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_28 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_126 {
private:
    static inline const CRegister<0x480001f8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_62 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_127 {
private:
    static inline const CRegister<0x480001fcUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_77 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_128 {
private:
    static inline const CRegister<0x48000200UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_14 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_129 {
private:
    static inline const CRegister<0x48000204UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_22 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_130 {
private:
    static inline const CRegister<0x48000208UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_70 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_131 {
private:
    static inline const CRegister<0x4800020cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_20 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_132 {
private:
    static inline const CRegister<0x48000210UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_94 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_133 {
private:
    static inline const CRegister<0x48000214UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_82 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_134 {
private:
    static inline const CRegister<0x48000218UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_98 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_135 {
private:
    static inline const CRegister<0x4800021cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_72 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_136 {
private:
    static inline const CRegister<0x48000220UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_1 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_137 {
private:
    static inline const CRegister<0x48000224UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_5 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_138 {
private:
    static inline const CRegister<0x48000228UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_76 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_139 {
private:
    static inline const CRegister<0x4800022cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_29 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_140 {
private:
    static inline const CRegister<0x48000230UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_7 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_141 {
private:
    static inline const CRegister<0x48000234UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_142 {
private:
    static inline const CRegister<0x48000238UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_56 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_143 {
private:
    static inline const CRegister<0x4800023cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_92 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_144 {
private:
    static inline const CRegister<0x48000240UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_51 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_145 {
private:
    static inline const CRegister<0x48000244UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_83 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_146 {
private:
    static inline const CRegister<0x48000248UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_39 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_147 {
private:
    static inline const CRegister<0x4800024cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_39 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_148 {
private:
    static inline const CRegister<0x48000250UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_39 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_149 {
private:
    static inline const CRegister<0x48000254UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_65 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_150 {
private:
    static inline const CRegister<0x48000258UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_92 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_151 {
private:
    static inline const CRegister<0x4800025cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_90 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_152 {
private:
    static inline const CRegister<0x48000260UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_153 {
private:
    static inline const CRegister<0x48000264UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_67 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_154 {
private:
    static inline const CRegister<0x48000268UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_91 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_155 {
private:
    static inline const CRegister<0x4800026cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_60 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_156 {
private:
    static inline const CRegister<0x48000270UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_20 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_157 {
private:
    static inline const CRegister<0x48000274UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_99 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_158 {
private:
    static inline const CRegister<0x48000278UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_54 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_159 {
private:
    static inline const CRegister<0x4800027cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_67 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_160 {
private:
    static inline const CRegister<0x48000280UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_2 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_161 {
private:
    static inline const CRegister<0x48000284UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_25 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_162 {
private:
    static inline const CRegister<0x48000288UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_77 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_163 {
private:
    static inline const CRegister<0x4800028cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_43 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_164 {
private:
    static inline const CRegister<0x48000290UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_11 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_165 {
private:
    static inline const CRegister<0x48000294UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_61 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_166 {
private:
    static inline const CRegister<0x48000298UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_7 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_167 {
private:
    static inline const CRegister<0x4800029cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_49 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_168 {
private:
    static inline const CRegister<0x480002a0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_169 {
private:
    static inline const CRegister<0x480002a4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_14 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_170 {
private:
    static inline const CRegister<0x480002a8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_54 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_171 {
private:
    static inline const CRegister<0x480002acUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_67 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_172 {
private:
    static inline const CRegister<0x480002b0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_22 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_173 {
private:
    static inline const CRegister<0x480002b4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_24 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_174 {
private:
    static inline const CRegister<0x480002b8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_37 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_175 {
private:
    static inline const CRegister<0x480002bcUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_176 {
private:
    static inline const CRegister<0x480002c0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_51 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_177 {
private:
    static inline const CRegister<0x480002c4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_26 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_178 {
private:
    static inline const CRegister<0x480002c8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_97 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_179 {
private:
    static inline const CRegister<0x480002ccUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_46 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_180 {
private:
    static inline const CRegister<0x480002d0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_64 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_181 {
private:
    static inline const CRegister<0x480002d4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_34 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_182 {
private:
    static inline const CRegister<0x480002d8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_183 {
private:
    static inline const CRegister<0x480002dcUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_56 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_184 {
private:
    static inline const CRegister<0x480002e0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_44 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_185 {
private:
    static inline const CRegister<0x480002e4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_82 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_186 {
private:
    static inline const CRegister<0x480002e8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_2 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_187 {
private:
    static inline const CRegister<0x480002ecUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_21 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_188 {
private:
    static inline const CRegister<0x480002f0UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_189 {
private:
    static inline const CRegister<0x480002f4UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_91 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_190 {
private:
    static inline const CRegister<0x480002f8UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_91 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_191 {
private:
    static inline const CRegister<0x480002fcUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_62 << (shift * 3);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_192 {
private:
    static inline const CRegister<0x48000300UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_42 << (shift * 4);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_193 {
private:
    static inline const CRegister<0x48000304UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_55 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_194 {
private:
    static inline const CRegister<0x48000308UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_81 << (shift * 2);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_195 {
private:
    static inline const CRegister<0x4800030cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_69 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_196 {
private:
    static inline const CRegister<0x48000310UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_79 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_197 {
private:
    static inline const CRegister<0x48000314UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_12 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_198 {
private:
    static inline const CRegister<0x48000318UL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_26 << (shift * 1);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_199 {
private:
    static inline const CRegister<0x4800031cUL> m_register {};

    static inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    static inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_66 << (shift * 0);
    }
public:
    static inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
typedef struct {
    uint8_t ST_0_member_0;
    ENUM_22 ST_0_member_1;
    uint32_t ST_0_member_2;
    ENUM_23 ST_0_member_3;
    uint32_t ST_0_member_4;
    ENUM_11 ST_0_member_5;
    ENUM_24 ST_0_member_6;
    ENUM_9 ST_0_member_7;
    ENUM_28 ST_0_member_8;
    ENUM_18 ST_0_member_9;
} ST_0;
typedef struct {
    ENUM_1 ST_1_member_0;
    ENUM_12 ST_1_member_1;
    ENUM_12 ST_1_member_2;
    ENUM_1 ST_1_member_3;
    ENUM_1 ST_1_member_4;
    ENUM_3 ST_1_member_5;
    ENUM_27 ST_1_member_6;
    ENUM_18 ST_1_member_7;
    ENUM_25 ST_1_member_8;
    ENUM_6 ST_1_member_9;
} ST_1;
typedef struct {
    ENUM_3 ST_2_member_0;
    ENUM_26 ST_2_member_1;
    ENUM_15 ST_2_member_2;
    ENUM_25 ST_2_member_3;
    uint16_t ST_2_member_4;
    ENUM_26 ST_2_member_5;
    ENUM_8 ST_2_member_6;
    ENUM_7 ST_2_member_7;
    ENUM_14 ST_2_member_8;
    int ST_2_member_9;
} ST_2;
typedef struct {
    uint8_t ST_3_member_0;
    ENUM_25 ST_3_member_1;
    ENUM_28 ST_3_member_2;
    ENUM_19 ST_3_member_3;
    ENUM_27 ST_3_member_4;
    ENUM_1 ST_3_member_5;
    ENUM_15 ST_3_member_6;
    ENUM_16 ST_3_member_7;
    ENUM_17 ST_3_member_8;
    ENUM_17 ST_3_member_9;
} ST_3;
typedef struct {
    ENUM_18 ST_4_member_0;
    int ST_4_member_1;
    int ST_4_member_2;
    ENUM_9 ST_4_member_3;
    ENUM_1 ST_4_member_4;
    ENUM_12 ST_4_member_5;
    ENUM_22 ST_4_member_6;
    ENUM_17 ST_4_member_7;
    ENUM_28 ST_4_member_8;
    ENUM_24 ST_4_member_9;
} ST_4;
typedef struct {
    ENUM_17 ST_5_member_0;
    ENUM_12 ST_5_member_1;
    uint8_t ST_5_member_2;
    ENUM_26 ST_5_member_3;
    ENUM_10 ST_5_member_4;
    ENUM_4 ST_5_member_5;
    ENUM_3 ST_5_member_6;
    ENUM_18 ST_5_member_7;
    ENUM_23 ST_5_member_8;
    ENUM_9 ST_5_member_9;
} ST_5;
typedef struct {
    ENUM_3 ST_6_member_0;
    ENUM_12 ST_6_member_1;
    ENUM_6 ST_6_member_2;
    ENUM_22 ST_6_member_3;
    ENUM_21 ST_6_member_4;
    ENUM_15 ST_6_member_5;
    ENUM_3 ST_6_member_6;
    ENUM_1 ST_6_member_7;
    ENUM_10 ST_6_member_8;
    ENUM_4 ST_6_member_9;
} ST_6;
typedef struct {
    ENUM_20 ST_7_member_0;
    ENUM_28 ST_7_member_1;
    ENUM_25 ST_7_member_2;
    ENUM_28 ST_7_member_3;
    ENUM_7 ST_7_member_4;
    ENUM_2 ST_7_member_5;
    ENUM_4 ST_7_member_6;
    uint16_t ST_7_member_7;
    ENUM_8 ST_7_member_8;
    ENUM_10 ST_7_member_9;
} ST_7;
typedef struct {
    int ST_8_member_0;
    ENUM_7 ST_8_member_1;
    ENUM_10 ST_8_member_2;
    ENUM_22 ST_8_member_3;
    ENUM_28 ST_8_member_4;
    ENUM_19 ST_8_member_5;
    ENUM_6 ST_8_member_6;
    uint16_t ST_8_member_7;
    ENUM_4 ST_8_member_8;
    ENUM_28 ST_8_member_9;
} ST_8;
typedef struct {
    ENUM_17 ST_9_member_0;
    ENUM_20 ST_9_member_1;
    ENUM_18 ST_9_member_2;
    ENUM_17 ST_9_member_3;
    ENUM_21 ST_9_member_4;
    ENUM_8 ST_9_member_5;
    ENUM_13 ST_9_member_6;
    int ST_9_member_7;
    ENUM_12 ST_9_member_8;
    ENUM_9 ST_9_member_9;
} ST_9;
typedef struct {
    ENUM_18 ST_10_member_0;
    ENUM_14 ST_10_member_1;
    ENUM_6 ST_10_member_2;
    ENUM_28 ST_10_member_3;
    ENUM_10 ST_10_member_4;
    ENUM_0 ST_10_member_5;
    ENUM_23 ST_10_member_6;
    ENUM_2 ST_10_member_7;
    ENUM_10 ST_10_member_8;
    ENUM_10 ST_10_member_9;
} ST_10;
typedef struct {
    ENUM_3 ST_11_member_0;
    ENUM_16 ST_11_member_1;
    ENUM_14 ST_11_member_2;
    ENUM_16 ST_11_member_3;
    ENUM_7 ST_11_member_4;
    ENUM_25 ST_11_member_5;
    ENUM_18 ST_11_member_6;
    ENUM_14 ST_11_member_7;
    ENUM_15 ST_11_member_8;
    uint32_t ST_11_member_9;
} ST_11;
typedef struct {
    ENUM_2 ST_12_member_0;
    ENUM_2 ST_12_member_1;
    ENUM_4 ST_12_member_2;
    ENUM_15 ST_12_member_3;
    ENUM_9 ST_12_member_4;
    ENUM_16 ST_12_member_5;
    ENUM_28 ST_12_member_6;
    ENUM_26 ST_12_member_7;
    ENUM_23 ST_12_member_8;
    ENUM_10 ST_12_member_9;
} ST_12;
typedef struct {
    ENUM_13 ST_13_member_0;
    uint16_t ST_13_member_1;
    ENUM_8 ST_13_member_2;
    ENUM_20 ST_13_member_3;
    ENUM_15 ST_13_member_4;
    ENUM_4 ST_13_member_5;
    ENUM_11 ST_13_member_6;
    uint8_t ST_13_member_7;
    ENUM_14 ST_13_member_8;
    ENUM_8 ST_13_member_9;
} ST_13;
typedef struct {
    ENUM_28 ST_14_member_0;
    ENUM_23 ST_14_member_1;
    ENUM_18 ST_14_member_2;
    ENUM_26 ST_14_member_3;
    int ST_14_member_4;
    ENUM_15 ST_14_member_5;
    ENUM_28 ST_14_member_6;
    uint32_t ST_14_member_7;
    ENUM_7 ST_14_member_8;
    ENUM_15 ST_14_member_9;
} ST_14;
typedef struct {
    ENUM_26 ST_15_member_0;
    ENUM_4 ST_15_member_1;
    ENUM_28 ST_15_member_2;
    ENUM_21 ST_15_member_3;
    ENUM_1 ST_15_member_4;
    ENUM_6 ST_15_member_5;
    ENUM_7 ST_15_member_6;
    ENUM_5 ST_15_member_7;
    ENUM_26 ST_15_member_8;
    ENUM_2 ST_15_member_9;
} ST_15;
typedef struct {
    uint32_t ST_16_member_0;
    ENUM_6 ST_16_member_1;
    ENUM_15 ST_16_member_2;
    ENUM_26 ST_16_member_3;
    ENUM_29 ST_16_member_4;
    ENUM_9 ST_16_member_5;
    ENUM_6 ST_16_member_6;
    int ST_16_member_7;
    ENUM_0 ST_16_member_8;
    ENUM_0 ST_16_member_9;
} ST_16;
typedef struct {
    uint8_t ST_17_member_0;
    ENUM_0 ST_17_member_1;
    ENUM_14 ST_17_member_2;
    ENUM_28 ST_17_member_3;
    ENUM_7 ST_17_member_4;
    ENUM_4 ST_17_member_5;
    ENUM_10 ST_17_member_6;
    ENUM_5 ST_17_member_7;
    ENUM_9 ST_17_member_8;
    ENUM_12 ST_17_member_9;
} ST_17;
typedef struct {
    ENUM_9 ST_18_member_0;
    ENUM_14 ST_18_member_1;
    ENUM_11 ST_18_member_2;
    ENUM_12 ST_18_member_3;
    ENUM_7 ST_18_member_4;
    ENUM_23 ST_18_member_5;
    ENUM_12 ST_18_member_6;
    ENUM_11 ST_18_member_7;
    ENUM_21 ST_18_member_8;
    ENUM_10 ST_18_member_9;
} ST_18;
typedef struct {
    ENUM_1 ST_19_member_0;
    ENUM_9 ST_19_member_1;
    ENUM_8 ST_19_member_2;
    uint32_t ST_19_member_3;
    ENUM_1 ST_19_member_4;
    ENUM_25 ST_19_member_5;
    ENUM_3 ST_19_member_6;
    uint8_t ST_19_member_7;
    ENUM_23 ST_19_member_8;
    ENUM_29 ST_19_member_9;
} ST_19;
void hal_func_0(ST_5* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_17(param->ST_5_member_0)) { return; }
    if (!IS_ENUM_12(param->ST_5_member_1)) { return; }
    if (!IS_ENUM_26(param->ST_5_member_3)) { return; }
    if (!IS_ENUM_10(param->ST_5_member_4)) { return; }
    if (!IS_ENUM_4(param->ST_5_member_5)) { return; }
    if (!IS_ENUM_3(param->ST_5_member_6)) { return; }
    if (!IS_ENUM_18(param->ST_5_member_7)) { return; }
    if (!IS_ENUM_23(param->ST_5_member_8)) { return; }
    if (!IS_ENUM_9(param->ST_5_member_9)) { return; }
    if (param->ST_5_member_9 == ENUM_9_VAL_8) {
        __attribute__((unused)) ENUM_17 val = param->ST_5_member_0;
        __attribute__((unused)) ENUM_4 shift = param->ST_5_member_5;
        CREG_186::configure(shift, val);
        CREG_129::configure(shift, val);
    }
    if (param->ST_5_member_8 == ENUM_23_VAL_1) {
        __attribute__((unused)) ENUM_12 val = param->ST_5_member_1;
        __attribute__((unused)) uint8_t shift = param->ST_5_member_2;
        CREG_199::configure(shift, val);
    }
}
void hal_func_1(ST_2* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_3(param->ST_2_member_0)) { return; }
    if (!IS_ENUM_26(param->ST_2_member_1)) { return; }
    if (!IS_ENUM_15(param->ST_2_member_2)) { return; }
    if (!IS_ENUM_25(param->ST_2_member_3)) { return; }
    if (!IS_ENUM_26(param->ST_2_member_5)) { return; }
    if (!IS_ENUM_8(param->ST_2_member_6)) { return; }
    if (!IS_ENUM_7(param->ST_2_member_7)) { return; }
    if (!IS_ENUM_14(param->ST_2_member_8)) { return; }
    if (param->ST_2_member_1 == ENUM_26_VAL_3) {
        __attribute__((unused)) uint16_t val = param->ST_2_member_4;
        __attribute__((unused)) int shift = param->ST_2_member_9;
        CREG_36::configure(shift, val);
        CREG_180::configure(shift, val);
        CREG_94::configure(shift, val);
        CREG_185::configure(shift, val);
        CREG_190::configure(shift, val);
    }
    if (param->ST_2_member_0 == ENUM_3_VAL_4) {
        __attribute__((unused)) ENUM_26 val = param->ST_2_member_5;
        __attribute__((unused)) ENUM_7 shift = param->ST_2_member_7;
        CREG_53::configure(shift, val);
        CREG_51::configure(shift, val);
        CREG_150::configure(shift, val);
        CREG_71::configure(shift, val);
    }
    if (param->ST_2_member_6 == ENUM_8_VAL_2) {
        __attribute__((unused)) int val = param->ST_2_member_9;
        __attribute__((unused)) ENUM_7 shift = param->ST_2_member_7;
        CREG_65::configure(shift, val);
        CREG_35::configure(shift, val);
        CREG_79::configure(shift, val);
    }
}
void hal_func_2(ST_19* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_1(param->ST_19_member_0)) { return; }
    if (!IS_ENUM_9(param->ST_19_member_1)) { return; }
    if (!IS_ENUM_8(param->ST_19_member_2)) { return; }
    if (!IS_ENUM_1(param->ST_19_member_4)) { return; }
    if (!IS_ENUM_25(param->ST_19_member_5)) { return; }
    if (!IS_ENUM_3(param->ST_19_member_6)) { return; }
    if (!IS_ENUM_23(param->ST_19_member_8)) { return; }
    if (!IS_ENUM_29(param->ST_19_member_9)) { return; }
    if (param->ST_19_member_0 == ENUM_1_VAL_4) {
        __attribute__((unused)) uint32_t val = param->ST_19_member_3;
        __attribute__((unused)) ENUM_25 shift = param->ST_19_member_5;
        CREG_98::configure(shift, val);
        CREG_123::configure(shift, val);
        CREG_132::configure(shift, val);
    }
    if (param->ST_19_member_2 == ENUM_8_VAL_0) {
        __attribute__((unused)) ENUM_25 val = param->ST_19_member_5;
        __attribute__((unused)) ENUM_25 shift = param->ST_19_member_5;
        CREG_3::configure(shift, val);
        CREG_151::configure(shift, val);
        CREG_198::configure(shift, val);
        CREG_71::configure(shift, val);
    }
    if (param->ST_19_member_4 == ENUM_1_VAL_1) {
        __attribute__((unused)) ENUM_25 val = param->ST_19_member_5;
        __attribute__((unused)) ENUM_9 shift = param->ST_19_member_1;
        CREG_143::configure(shift, val);
        CREG_144::configure(shift, val);
        CREG_186::configure(shift, val);
        CREG_37::configure(shift, val);
        CREG_167::configure(shift, val);
    }
}
void hal_func_3(ST_18* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_9(param->ST_18_member_0)) { return; }
    if (!IS_ENUM_14(param->ST_18_member_1)) { return; }
    if (!IS_ENUM_11(param->ST_18_member_2)) { return; }
    if (!IS_ENUM_12(param->ST_18_member_3)) { return; }
    if (!IS_ENUM_7(param->ST_18_member_4)) { return; }
    if (!IS_ENUM_23(param->ST_18_member_5)) { return; }
    if (!IS_ENUM_12(param->ST_18_member_6)) { return; }
    if (!IS_ENUM_11(param->ST_18_member_7)) { return; }
    if (!IS_ENUM_21(param->ST_18_member_8)) { return; }
    if (!IS_ENUM_10(param->ST_18_member_9)) { return; }
    if (param->ST_18_member_7 == ENUM_11_VAL_6) {
        __attribute__((unused)) ENUM_12 val = param->ST_18_member_6;
        __attribute__((unused)) ENUM_12 shift = param->ST_18_member_6;
        CREG_26::configure(shift, val);
        CREG_139::configure(shift, val);
        CREG_24::configure(shift, val);
        CREG_181::configure(shift, val);
        CREG_134::configure(shift, val);
    }
    if (param->ST_18_member_2 == ENUM_11_VAL_3) {
        __attribute__((unused)) ENUM_12 val = param->ST_18_member_6;
        __attribute__((unused)) ENUM_21 shift = param->ST_18_member_8;
        CREG_58::configure(shift, val);
        CREG_5::configure(shift, val);
        CREG_164::configure(shift, val);
    }
    if (param->ST_18_member_6 == ENUM_12_VAL_6) {
        __attribute__((unused)) ENUM_23 val = param->ST_18_member_5;
        __attribute__((unused)) ENUM_14 shift = param->ST_18_member_1;
        CREG_154::configure(shift, val);
        CREG_91::configure(shift, val);
        CREG_15::configure(shift, val);
        CREG_57::configure(shift, val);
        CREG_142::configure(shift, val);
    }
    if (param->ST_18_member_9 == ENUM_10_VAL_1) {
        __attribute__((unused)) ENUM_21 val = param->ST_18_member_8;
        __attribute__((unused)) ENUM_14 shift = param->ST_18_member_1;
        CREG_132::configure(shift, val);
        CREG_126::configure(shift, val);
    }
}
void hal_func_4(ST_9* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_17(param->ST_9_member_0)) { return; }
    if (!IS_ENUM_20(param->ST_9_member_1)) { return; }
    if (!IS_ENUM_18(param->ST_9_member_2)) { return; }
    if (!IS_ENUM_17(param->ST_9_member_3)) { return; }
    if (!IS_ENUM_21(param->ST_9_member_4)) { return; }
    if (!IS_ENUM_8(param->ST_9_member_5)) { return; }
    if (!IS_ENUM_13(param->ST_9_member_6)) { return; }
    if (!IS_ENUM_12(param->ST_9_member_8)) { return; }
    if (!IS_ENUM_9(param->ST_9_member_9)) { return; }
    if (param->ST_9_member_6 == ENUM_13_VAL_6) {
        __attribute__((unused)) ENUM_18 val = param->ST_9_member_2;
        __attribute__((unused)) ENUM_21 shift = param->ST_9_member_4;
        CREG_188::configure(shift, val);
        CREG_130::configure(shift, val);
    }
    if (param->ST_9_member_8 == ENUM_12_VAL_4) {
        __attribute__((unused)) ENUM_18 val = param->ST_9_member_2;
        __attribute__((unused)) ENUM_13 shift = param->ST_9_member_6;
        CREG_144::configure(shift, val);
        CREG_75::configure(shift, val);
        CREG_194::configure(shift, val);
    }
    if (param->ST_9_member_8 == ENUM_12_VAL_2) {
        __attribute__((unused)) ENUM_12 val = param->ST_9_member_8;
        __attribute__((unused)) ENUM_8 shift = param->ST_9_member_5;
        CREG_146::configure(shift, val);
    }
    if (param->ST_9_member_8 == ENUM_12_VAL_8) {
        __attribute__((unused)) ENUM_17 val = param->ST_9_member_3;
        __attribute__((unused)) ENUM_17 shift = param->ST_9_member_3;
        CREG_82::configure(shift, val);
        CREG_153::configure(shift, val);
    }
}
void hal_func_5(ST_12* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_2(param->ST_12_member_0)) { return; }
    if (!IS_ENUM_2(param->ST_12_member_1)) { return; }
    if (!IS_ENUM_4(param->ST_12_member_2)) { return; }
    if (!IS_ENUM_15(param->ST_12_member_3)) { return; }
    if (!IS_ENUM_9(param->ST_12_member_4)) { return; }
    if (!IS_ENUM_16(param->ST_12_member_5)) { return; }
    if (!IS_ENUM_28(param->ST_12_member_6)) { return; }
    if (!IS_ENUM_26(param->ST_12_member_7)) { return; }
    if (!IS_ENUM_23(param->ST_12_member_8)) { return; }
    if (!IS_ENUM_10(param->ST_12_member_9)) { return; }
    if (param->ST_12_member_0 == ENUM_2_VAL_7) {
        __attribute__((unused)) ENUM_23 val = param->ST_12_member_8;
        __attribute__((unused)) ENUM_4 shift = param->ST_12_member_2;
        CREG_160::configure(shift, val);
        CREG_12::configure(shift, val);
        CREG_130::configure(shift, val);
        CREG_134::configure(shift, val);
    }
    if (param->ST_12_member_7 == ENUM_26_VAL_7) {
        __attribute__((unused)) ENUM_16 val = param->ST_12_member_5;
        __attribute__((unused)) ENUM_16 shift = param->ST_12_member_5;
        CREG_94::configure(shift, val);
    }
    if (param->ST_12_member_3 == ENUM_15_VAL_3) {
        __attribute__((unused)) ENUM_28 val = param->ST_12_member_6;
        __attribute__((unused)) ENUM_26 shift = param->ST_12_member_7;
        CREG_74::configure(shift, val);
        CREG_171::configure(shift, val);
        CREG_109::configure(shift, val);
        CREG_113::configure(shift, val);
    }
    if (param->ST_12_member_9 == ENUM_10_VAL_3) {
        __attribute__((unused)) ENUM_4 val = param->ST_12_member_2;
        __attribute__((unused)) ENUM_15 shift = param->ST_12_member_3;
        CREG_114::configure(shift, val);
        CREG_135::configure(shift, val);
        CREG_98::configure(shift, val);
        CREG_142::configure(shift, val);
        CREG_158::configure(shift, val);
    }
}
void hal_func_6(ST_17* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_0(param->ST_17_member_1)) { return; }
    if (!IS_ENUM_14(param->ST_17_member_2)) { return; }
    if (!IS_ENUM_28(param->ST_17_member_3)) { return; }
    if (!IS_ENUM_7(param->ST_17_member_4)) { return; }
    if (!IS_ENUM_4(param->ST_17_member_5)) { return; }
    if (!IS_ENUM_10(param->ST_17_member_6)) { return; }
    if (!IS_ENUM_5(param->ST_17_member_7)) { return; }
    if (!IS_ENUM_9(param->ST_17_member_8)) { return; }
    if (!IS_ENUM_12(param->ST_17_member_9)) { return; }
    if (param->ST_17_member_3 == ENUM_28_VAL_5) {
        __attribute__((unused)) ENUM_7 val = param->ST_17_member_4;
        __attribute__((unused)) ENUM_10 shift = param->ST_17_member_6;
        CREG_7::configure(shift, val);
        CREG_183::configure(shift, val);
    }
    if (param->ST_17_member_5 == ENUM_4_VAL_1) {
        __attribute__((unused)) ENUM_14 val = param->ST_17_member_2;
        __attribute__((unused)) ENUM_0 shift = param->ST_17_member_1;
        CREG_62::configure(shift, val);
        CREG_150::configure(shift, val);
        CREG_13::configure(shift, val);
        CREG_17::configure(shift, val);
    }
    if (param->ST_17_member_2 == ENUM_14_VAL_0) {
        __attribute__((unused)) uint8_t val = param->ST_17_member_0;
        __attribute__((unused)) ENUM_28 shift = param->ST_17_member_3;
        CREG_81::configure(shift, val);
        CREG_35::configure(shift, val);
    }
    if (param->ST_17_member_2 == ENUM_14_VAL_3) {
        __attribute__((unused)) ENUM_7 val = param->ST_17_member_4;
        __attribute__((unused)) uint8_t shift = param->ST_17_member_0;
        CREG_9::configure(shift, val);
        CREG_56::configure(shift, val);
        CREG_95::configure(shift, val);
    }
}
void hal_func_7(ST_3* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_25(param->ST_3_member_1)) { return; }
    if (!IS_ENUM_28(param->ST_3_member_2)) { return; }
    if (!IS_ENUM_19(param->ST_3_member_3)) { return; }
    if (!IS_ENUM_27(param->ST_3_member_4)) { return; }
    if (!IS_ENUM_1(param->ST_3_member_5)) { return; }
    if (!IS_ENUM_15(param->ST_3_member_6)) { return; }
    if (!IS_ENUM_16(param->ST_3_member_7)) { return; }
    if (!IS_ENUM_17(param->ST_3_member_8)) { return; }
    if (!IS_ENUM_17(param->ST_3_member_9)) { return; }
    if (param->ST_3_member_2 == ENUM_28_VAL_6) {
        __attribute__((unused)) ENUM_15 val = param->ST_3_member_6;
        __attribute__((unused)) ENUM_17 shift = param->ST_3_member_9;
        CREG_63::configure(shift, val);
    }
    if (param->ST_3_member_9 == ENUM_17_VAL_7) {
        __attribute__((unused)) ENUM_19 val = param->ST_3_member_3;
        __attribute__((unused)) uint8_t shift = param->ST_3_member_0;
        CREG_59::configure(shift, val);
        CREG_33::configure(shift, val);
        CREG_171::configure(shift, val);
        CREG_95::configure(shift, val);
        CREG_199::configure(shift, val);
    }
    if (param->ST_3_member_5 == ENUM_1_VAL_2) {
        __attribute__((unused)) ENUM_28 val = param->ST_3_member_2;
        __attribute__((unused)) ENUM_19 shift = param->ST_3_member_3;
        CREG_86::configure(shift, val);
        CREG_126::configure(shift, val);
        CREG_96::configure(shift, val);
    }
    if (param->ST_3_member_2 == ENUM_28_VAL_1) {
        __attribute__((unused)) ENUM_27 val = param->ST_3_member_4;
        __attribute__((unused)) ENUM_27 shift = param->ST_3_member_4;
        CREG_55::configure(shift, val);
        CREG_111::configure(shift, val);
    }
}
void hal_func_8(ST_9* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_17(param->ST_9_member_0)) { return; }
    if (!IS_ENUM_20(param->ST_9_member_1)) { return; }
    if (!IS_ENUM_18(param->ST_9_member_2)) { return; }
    if (!IS_ENUM_17(param->ST_9_member_3)) { return; }
    if (!IS_ENUM_21(param->ST_9_member_4)) { return; }
    if (!IS_ENUM_8(param->ST_9_member_5)) { return; }
    if (!IS_ENUM_13(param->ST_9_member_6)) { return; }
    if (!IS_ENUM_12(param->ST_9_member_8)) { return; }
    if (!IS_ENUM_9(param->ST_9_member_9)) { return; }
    if (param->ST_9_member_9 == ENUM_9_VAL_8) {
        __attribute__((unused)) ENUM_20 val = param->ST_9_member_1;
        __attribute__((unused)) ENUM_18 shift = param->ST_9_member_2;
        CREG_100::configure(shift, val);
    }
    if (param->ST_9_member_8 == ENUM_12_VAL_9) {
        __attribute__((unused)) ENUM_13 val = param->ST_9_member_6;
        __attribute__((unused)) ENUM_8 shift = param->ST_9_member_5;
        CREG_45::configure(shift, val);
        CREG_49::configure(shift, val);
    }
    if (param->ST_9_member_8 == ENUM_12_VAL_9) {
        __attribute__((unused)) ENUM_21 val = param->ST_9_member_4;
        __attribute__((unused)) ENUM_13 shift = param->ST_9_member_6;
        CREG_29::configure(shift, val);
        CREG_155::configure(shift, val);
    }
    if (param->ST_9_member_0 == ENUM_17_VAL_8) {
        __attribute__((unused)) ENUM_9 val = param->ST_9_member_9;
        __attribute__((unused)) int shift = param->ST_9_member_7;
        CREG_190::configure(shift, val);
        CREG_136::configure(shift, val);
        CREG_52::configure(shift, val);
        CREG_44::configure(shift, val);
        CREG_181::configure(shift, val);
    }
}
void hal_func_9(ST_18* param) {
    __attribute__((unused)) uint32_t temp;

    /* check the values */
    if (!IS_ENUM_9(param->ST_18_member_0)) { return; }
    if (!IS_ENUM_14(param->ST_18_member_1)) { return; }
    if (!IS_ENUM_11(param->ST_18_member_2)) { return; }
    if (!IS_ENUM_12(param->ST_18_member_3)) { return; }
    if (!IS_ENUM_7(param->ST_18_member_4)) { return; }
    if (!IS_ENUM_23(param->ST_18_member_5)) { return; }
    if (!IS_ENUM_12(param->ST_18_member_6)) { return; }
    if (!IS_ENUM_11(param->ST_18_member_7)) { return; }
    if (!IS_ENUM_21(param->ST_18_member_8)) { return; }
    if (!IS_ENUM_10(param->ST_18_member_9)) { return; }
    if (param->ST_18_member_4 == ENUM_7_VAL_7) {
        __attribute__((unused)) ENUM_23 val = param->ST_18_member_5;
        __attribute__((unused)) ENUM_21 shift = param->ST_18_member_8;
        CREG_1::configure(shift, val);
        CREG_33::configure(shift, val);
        CREG_83::configure(shift, val);
        CREG_112::configure(shift, val);
    }
    if (param->ST_18_member_9 == ENUM_10_VAL_1) {
        __attribute__((unused)) ENUM_11 val = param->ST_18_member_2;
        __attribute__((unused)) ENUM_21 shift = param->ST_18_member_8;
        CREG_105::configure(shift, val);
        CREG_94::configure(shift, val);
        CREG_88::configure(shift, val);
        CREG_168::configure(shift, val);
        CREG_54::configure(shift, val);
    }
    if (param->ST_18_member_8 == ENUM_21_VAL_0) {
        __attribute__((unused)) ENUM_23 val = param->ST_18_member_5;
        __attribute__((unused)) ENUM_9 shift = param->ST_18_member_0;
        CREG_91::configure(shift, val);
        CREG_184::configure(shift, val);
        CREG_70::configure(shift, val);
        CREG_193::configure(shift, val);
    }
    if (param->ST_18_member_1 == ENUM_14_VAL_1) {
        __attribute__((unused)) ENUM_21 val = param->ST_18_member_8;
        __attribute__((unused)) ENUM_12 shift = param->ST_18_member_3;
        CREG_37::configure(shift, val);
        CREG_24::configure(shift, val);
        CREG_177::configure(shift, val);
    }
}

int main (void) {
    __attribute__((unused)) ST_0 inst_ST_0 {};
    inst_ST_0.ST_0_member_0 = 63;
    inst_ST_0.ST_0_member_1 = ENUM_22_VAL_5;
    inst_ST_0.ST_0_member_2 = 50;
    inst_ST_0.ST_0_member_3 = ENUM_23_VAL_7;
    inst_ST_0.ST_0_member_4 = 29;
    inst_ST_0.ST_0_member_5 = ENUM_11_VAL_1;
    inst_ST_0.ST_0_member_6 = ENUM_24_VAL_5;
    inst_ST_0.ST_0_member_7 = ENUM_9_VAL_8;
    inst_ST_0.ST_0_member_8 = ENUM_28_VAL_5;
    inst_ST_0.ST_0_member_9 = ENUM_18_VAL_3;
    __attribute__((unused)) ST_1 inst_ST_1 {};
    inst_ST_1.ST_1_member_0 = ENUM_1_VAL_9;
    inst_ST_1.ST_1_member_1 = ENUM_12_VAL_9;
    inst_ST_1.ST_1_member_2 = ENUM_12_VAL_9;
    inst_ST_1.ST_1_member_3 = ENUM_1_VAL_3;
    inst_ST_1.ST_1_member_4 = ENUM_1_VAL_5;
    inst_ST_1.ST_1_member_5 = ENUM_3_VAL_0;
    inst_ST_1.ST_1_member_6 = ENUM_27_VAL_2;
    inst_ST_1.ST_1_member_7 = ENUM_18_VAL_4;
    inst_ST_1.ST_1_member_8 = ENUM_25_VAL_9;
    inst_ST_1.ST_1_member_9 = ENUM_6_VAL_9;
    __attribute__((unused)) ST_2 inst_ST_2 {};
    inst_ST_2.ST_2_member_0 = ENUM_3_VAL_3;
    inst_ST_2.ST_2_member_1 = ENUM_26_VAL_6;
    inst_ST_2.ST_2_member_2 = ENUM_15_VAL_3;
    inst_ST_2.ST_2_member_3 = ENUM_25_VAL_8;
    inst_ST_2.ST_2_member_4 = 88;
    inst_ST_2.ST_2_member_5 = ENUM_26_VAL_5;
    inst_ST_2.ST_2_member_6 = ENUM_8_VAL_5;
    inst_ST_2.ST_2_member_7 = ENUM_7_VAL_0;
    inst_ST_2.ST_2_member_8 = ENUM_14_VAL_0;
    inst_ST_2.ST_2_member_9 = 62;
    __attribute__((unused)) ST_3 inst_ST_3 {};
    inst_ST_3.ST_3_member_0 = 14;
    inst_ST_3.ST_3_member_1 = ENUM_25_VAL_7;
    inst_ST_3.ST_3_member_2 = ENUM_28_VAL_6;
    inst_ST_3.ST_3_member_3 = ENUM_19_VAL_5;
    inst_ST_3.ST_3_member_4 = ENUM_27_VAL_9;
    inst_ST_3.ST_3_member_5 = ENUM_1_VAL_7;
    inst_ST_3.ST_3_member_6 = ENUM_15_VAL_0;
    inst_ST_3.ST_3_member_7 = ENUM_16_VAL_7;
    inst_ST_3.ST_3_member_8 = ENUM_17_VAL_3;
    inst_ST_3.ST_3_member_9 = ENUM_17_VAL_3;
    __attribute__((unused)) ST_4 inst_ST_4 {};
    inst_ST_4.ST_4_member_0 = ENUM_18_VAL_4;
    inst_ST_4.ST_4_member_1 = 38;
    inst_ST_4.ST_4_member_2 = 13;
    inst_ST_4.ST_4_member_3 = ENUM_9_VAL_8;
    inst_ST_4.ST_4_member_4 = ENUM_1_VAL_9;
    inst_ST_4.ST_4_member_5 = ENUM_12_VAL_8;
    inst_ST_4.ST_4_member_6 = ENUM_22_VAL_9;
    inst_ST_4.ST_4_member_7 = ENUM_17_VAL_1;
    inst_ST_4.ST_4_member_8 = ENUM_28_VAL_2;
    inst_ST_4.ST_4_member_9 = ENUM_24_VAL_1;
    __attribute__((unused)) ST_5 inst_ST_5 {};
    inst_ST_5.ST_5_member_0 = ENUM_17_VAL_0;
    inst_ST_5.ST_5_member_1 = ENUM_12_VAL_4;
    inst_ST_5.ST_5_member_2 = 62;
    inst_ST_5.ST_5_member_3 = ENUM_26_VAL_8;
    inst_ST_5.ST_5_member_4 = ENUM_10_VAL_7;
    inst_ST_5.ST_5_member_5 = ENUM_4_VAL_7;
    inst_ST_5.ST_5_member_6 = ENUM_3_VAL_3;
    inst_ST_5.ST_5_member_7 = ENUM_18_VAL_2;
    inst_ST_5.ST_5_member_8 = ENUM_23_VAL_3;
    inst_ST_5.ST_5_member_9 = ENUM_9_VAL_9;
    __attribute__((unused)) ST_6 inst_ST_6 {};
    inst_ST_6.ST_6_member_0 = ENUM_3_VAL_5;
    inst_ST_6.ST_6_member_1 = ENUM_12_VAL_6;
    inst_ST_6.ST_6_member_2 = ENUM_6_VAL_8;
    inst_ST_6.ST_6_member_3 = ENUM_22_VAL_3;
    inst_ST_6.ST_6_member_4 = ENUM_21_VAL_5;
    inst_ST_6.ST_6_member_5 = ENUM_15_VAL_0;
    inst_ST_6.ST_6_member_6 = ENUM_3_VAL_7;
    inst_ST_6.ST_6_member_7 = ENUM_1_VAL_5;
    inst_ST_6.ST_6_member_8 = ENUM_10_VAL_3;
    inst_ST_6.ST_6_member_9 = ENUM_4_VAL_7;
    __attribute__((unused)) ST_7 inst_ST_7 {};
    inst_ST_7.ST_7_member_0 = ENUM_20_VAL_2;
    inst_ST_7.ST_7_member_1 = ENUM_28_VAL_0;
    inst_ST_7.ST_7_member_2 = ENUM_25_VAL_3;
    inst_ST_7.ST_7_member_3 = ENUM_28_VAL_9;
    inst_ST_7.ST_7_member_4 = ENUM_7_VAL_8;
    inst_ST_7.ST_7_member_5 = ENUM_2_VAL_5;
    inst_ST_7.ST_7_member_6 = ENUM_4_VAL_5;
    inst_ST_7.ST_7_member_7 = 42;
    inst_ST_7.ST_7_member_8 = ENUM_8_VAL_1;
    inst_ST_7.ST_7_member_9 = ENUM_10_VAL_3;
    __attribute__((unused)) ST_8 inst_ST_8 {};
    inst_ST_8.ST_8_member_0 = 72;
    inst_ST_8.ST_8_member_1 = ENUM_7_VAL_9;
    inst_ST_8.ST_8_member_2 = ENUM_10_VAL_7;
    inst_ST_8.ST_8_member_3 = ENUM_22_VAL_2;
    inst_ST_8.ST_8_member_4 = ENUM_28_VAL_0;
    inst_ST_8.ST_8_member_5 = ENUM_19_VAL_5;
    inst_ST_8.ST_8_member_6 = ENUM_6_VAL_7;
    inst_ST_8.ST_8_member_7 = 78;
    inst_ST_8.ST_8_member_8 = ENUM_4_VAL_8;
    inst_ST_8.ST_8_member_9 = ENUM_28_VAL_1;
    __attribute__((unused)) ST_9 inst_ST_9 {};
    inst_ST_9.ST_9_member_0 = ENUM_17_VAL_9;
    inst_ST_9.ST_9_member_1 = ENUM_20_VAL_8;
    inst_ST_9.ST_9_member_2 = ENUM_18_VAL_6;
    inst_ST_9.ST_9_member_3 = ENUM_17_VAL_8;
    inst_ST_9.ST_9_member_4 = ENUM_21_VAL_7;
    inst_ST_9.ST_9_member_5 = ENUM_8_VAL_3;
    inst_ST_9.ST_9_member_6 = ENUM_13_VAL_7;
    inst_ST_9.ST_9_member_7 = 54;
    inst_ST_9.ST_9_member_8 = ENUM_12_VAL_0;
    inst_ST_9.ST_9_member_9 = ENUM_9_VAL_2;
    __attribute__((unused)) ST_10 inst_ST_10 {};
    inst_ST_10.ST_10_member_0 = ENUM_18_VAL_5;
    inst_ST_10.ST_10_member_1 = ENUM_14_VAL_3;
    inst_ST_10.ST_10_member_2 = ENUM_6_VAL_2;
    inst_ST_10.ST_10_member_3 = ENUM_28_VAL_2;
    inst_ST_10.ST_10_member_4 = ENUM_10_VAL_9;
    inst_ST_10.ST_10_member_5 = ENUM_0_VAL_6;
    inst_ST_10.ST_10_member_6 = ENUM_23_VAL_2;
    inst_ST_10.ST_10_member_7 = ENUM_2_VAL_1;
    inst_ST_10.ST_10_member_8 = ENUM_10_VAL_1;
    inst_ST_10.ST_10_member_9 = ENUM_10_VAL_4;
    __attribute__((unused)) ST_11 inst_ST_11 {};
    inst_ST_11.ST_11_member_0 = ENUM_3_VAL_3;
    inst_ST_11.ST_11_member_1 = ENUM_16_VAL_4;
    inst_ST_11.ST_11_member_2 = ENUM_14_VAL_3;
    inst_ST_11.ST_11_member_3 = ENUM_16_VAL_6;
    inst_ST_11.ST_11_member_4 = ENUM_7_VAL_6;
    inst_ST_11.ST_11_member_5 = ENUM_25_VAL_9;
    inst_ST_11.ST_11_member_6 = ENUM_18_VAL_3;
    inst_ST_11.ST_11_member_7 = ENUM_14_VAL_0;
    inst_ST_11.ST_11_member_8 = ENUM_15_VAL_0;
    inst_ST_11.ST_11_member_9 = 48;
    __attribute__((unused)) ST_12 inst_ST_12 {};
    inst_ST_12.ST_12_member_0 = ENUM_2_VAL_2;
    inst_ST_12.ST_12_member_1 = ENUM_2_VAL_0;
    inst_ST_12.ST_12_member_2 = ENUM_4_VAL_2;
    inst_ST_12.ST_12_member_3 = ENUM_15_VAL_9;
    inst_ST_12.ST_12_member_4 = ENUM_9_VAL_7;
    inst_ST_12.ST_12_member_5 = ENUM_16_VAL_2;
    inst_ST_12.ST_12_member_6 = ENUM_28_VAL_1;
    inst_ST_12.ST_12_member_7 = ENUM_26_VAL_7;
    inst_ST_12.ST_12_member_8 = ENUM_23_VAL_4;
    inst_ST_12.ST_12_member_9 = ENUM_10_VAL_5;
    __attribute__((unused)) ST_13 inst_ST_13 {};
    inst_ST_13.ST_13_member_0 = ENUM_13_VAL_8;
    inst_ST_13.ST_13_member_1 = 67;
    inst_ST_13.ST_13_member_2 = ENUM_8_VAL_7;
    inst_ST_13.ST_13_member_3 = ENUM_20_VAL_1;
    inst_ST_13.ST_13_member_4 = ENUM_15_VAL_7;
    inst_ST_13.ST_13_member_5 = ENUM_4_VAL_1;
    inst_ST_13.ST_13_member_6 = ENUM_11_VAL_4;
    inst_ST_13.ST_13_member_7 = 22;
    inst_ST_13.ST_13_member_8 = ENUM_14_VAL_8;
    inst_ST_13.ST_13_member_9 = ENUM_8_VAL_7;
    __attribute__((unused)) ST_14 inst_ST_14 {};
    inst_ST_14.ST_14_member_0 = ENUM_28_VAL_0;
    inst_ST_14.ST_14_member_1 = ENUM_23_VAL_5;
    inst_ST_14.ST_14_member_2 = ENUM_18_VAL_3;
    inst_ST_14.ST_14_member_3 = ENUM_26_VAL_4;
    inst_ST_14.ST_14_member_4 = 7;
    inst_ST_14.ST_14_member_5 = ENUM_15_VAL_0;
    inst_ST_14.ST_14_member_6 = ENUM_28_VAL_8;
    inst_ST_14.ST_14_member_7 = 49;
    inst_ST_14.ST_14_member_8 = ENUM_7_VAL_4;
    inst_ST_14.ST_14_member_9 = ENUM_15_VAL_7;
    __attribute__((unused)) ST_15 inst_ST_15 {};
    inst_ST_15.ST_15_member_0 = ENUM_26_VAL_3;
    inst_ST_15.ST_15_member_1 = ENUM_4_VAL_8;
    inst_ST_15.ST_15_member_2 = ENUM_28_VAL_5;
    inst_ST_15.ST_15_member_3 = ENUM_21_VAL_0;
    inst_ST_15.ST_15_member_4 = ENUM_1_VAL_8;
    inst_ST_15.ST_15_member_5 = ENUM_6_VAL_7;
    inst_ST_15.ST_15_member_6 = ENUM_7_VAL_5;
    inst_ST_15.ST_15_member_7 = ENUM_5_VAL_4;
    inst_ST_15.ST_15_member_8 = ENUM_26_VAL_1;
    inst_ST_15.ST_15_member_9 = ENUM_2_VAL_0;
    __attribute__((unused)) ST_16 inst_ST_16 {};
    inst_ST_16.ST_16_member_0 = 93;
    inst_ST_16.ST_16_member_1 = ENUM_6_VAL_3;
    inst_ST_16.ST_16_member_2 = ENUM_15_VAL_3;
    inst_ST_16.ST_16_member_3 = ENUM_26_VAL_0;
    inst_ST_16.ST_16_member_4 = ENUM_29_VAL_9;
    inst_ST_16.ST_16_member_5 = ENUM_9_VAL_6;
    inst_ST_16.ST_16_member_6 = ENUM_6_VAL_6;
    inst_ST_16.ST_16_member_7 = 38;
    inst_ST_16.ST_16_member_8 = ENUM_0_VAL_0;
    inst_ST_16.ST_16_member_9 = ENUM_0_VAL_4;
    __attribute__((unused)) ST_17 inst_ST_17 {};
    inst_ST_17.ST_17_member_0 = 51;
    inst_ST_17.ST_17_member_1 = ENUM_0_VAL_5;
    inst_ST_17.ST_17_member_2 = ENUM_14_VAL_5;
    inst_ST_17.ST_17_member_3 = ENUM_28_VAL_5;
    inst_ST_17.ST_17_member_4 = ENUM_7_VAL_0;
    inst_ST_17.ST_17_member_5 = ENUM_4_VAL_5;
    inst_ST_17.ST_17_member_6 = ENUM_10_VAL_4;
    inst_ST_17.ST_17_member_7 = ENUM_5_VAL_0;
    inst_ST_17.ST_17_member_8 = ENUM_9_VAL_1;
    inst_ST_17.ST_17_member_9 = ENUM_12_VAL_7;
    __attribute__((unused)) ST_18 inst_ST_18 {};
    inst_ST_18.ST_18_member_0 = ENUM_9_VAL_2;
    inst_ST_18.ST_18_member_1 = ENUM_14_VAL_3;
    inst_ST_18.ST_18_member_2 = ENUM_11_VAL_9;
    inst_ST_18.ST_18_member_3 = ENUM_12_VAL_0;
    inst_ST_18.ST_18_member_4 = ENUM_7_VAL_3;
    inst_ST_18.ST_18_member_5 = ENUM_23_VAL_7;
    inst_ST_18.ST_18_member_6 = ENUM_12_VAL_6;
    inst_ST_18.ST_18_member_7 = ENUM_11_VAL_6;
    inst_ST_18.ST_18_member_8 = ENUM_21_VAL_3;
    inst_ST_18.ST_18_member_9 = ENUM_10_VAL_0;
    __attribute__((unused)) ST_19 inst_ST_19 {};
    inst_ST_19.ST_19_member_0 = ENUM_1_VAL_2;
    inst_ST_19.ST_19_member_1 = ENUM_9_VAL_2;
    inst_ST_19.ST_19_member_2 = ENUM_8_VAL_7;
    inst_ST_19.ST_19_member_3 = 33;
    inst_ST_19.ST_19_member_4 = ENUM_1_VAL_5;
    inst_ST_19.ST_19_member_5 = ENUM_25_VAL_4;
    inst_ST_19.ST_19_member_6 = ENUM_3_VAL_0;
    inst_ST_19.ST_19_member_7 = 22;
    inst_ST_19.ST_19_member_8 = ENUM_23_VAL_4;
    inst_ST_19.ST_19_member_9 = ENUM_29_VAL_9;
    hal_func_1(&inst_ST_2);
    hal_func_2(&inst_ST_19);
    hal_func_5(&inst_ST_12);
    hal_func_9(&inst_ST_18);
    hal_func_7(&inst_ST_3);
    hal_func_4(&inst_ST_9);
    hal_func_4(&inst_ST_9);
    hal_func_5(&inst_ST_12);
    hal_func_5(&inst_ST_12);
    hal_func_9(&inst_ST_18);

    while (1) {}
}