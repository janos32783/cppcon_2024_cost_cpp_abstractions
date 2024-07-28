#include <cstdint>

class CRegister {
private:
    const std::uint32_t m_address;
public:
    CRegister (std::uint32_t address) : m_address(address) { }

    void set (std::uint32_t val) const {
        *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) = val;
    }

    std::uint32_t get () const {
        return *(reinterpret_cast<volatile std::uint32_t *>(this->m_address));
    }

    void set (std::uint32_t value, std::uint32_t bitmask) const {
        std::uint32_t tmp = this->get();
        tmp &= ~bitmask;
        tmp |= value;
        this->set(tmp);
    }

    void set_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) = *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) | bitmask;
    }

    void clear_bits (std::uint32_t bitmask) {
        *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) = *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) & ~bitmask;
    }

    bool is_set (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) & bitmask) == bitmask;
    }

    bool is_cleared (std::uint32_t bitmask) {
        return (*(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) & bitmask) == 0;
    }

    std::uint32_t get_bits (std::uint32_t bitmask) {
        return *(reinterpret_cast<volatile std::uint32_t *>(this->m_address)) & bitmask;
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
    const CRegister m_register { 0x48000000UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_75 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_1 {
private:
    const CRegister m_register { 0x48000004UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_88 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_2 {
private:
    const CRegister m_register { 0x48000008UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_95 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_3 {
private:
    const CRegister m_register { 0x4800000cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_14 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_4 {
private:
    const CRegister m_register { 0x48000010UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_65 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_5 {
private:
    const CRegister m_register { 0x48000014UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_87 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_6 {
private:
    const CRegister m_register { 0x48000018UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_85 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_7 {
private:
    const CRegister m_register { 0x4800001cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_13 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_8 {
private:
    const CRegister m_register { 0x48000020UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_76 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_9 {
private:
    const CRegister m_register { 0x48000024UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_47 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_10 {
private:
    const CRegister m_register { 0x48000028UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_29 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_11 {
private:
    const CRegister m_register { 0x4800002cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_71 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_12 {
private:
    const CRegister m_register { 0x48000030UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_81 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_13 {
private:
    const CRegister m_register { 0x48000034UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_88 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_14 {
private:
    const CRegister m_register { 0x48000038UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_47 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_15 {
private:
    const CRegister m_register { 0x4800003cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_2 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_16 {
private:
    const CRegister m_register { 0x48000040UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_22 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_17 {
private:
    const CRegister m_register { 0x48000044UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_45 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_18 {
private:
    const CRegister m_register { 0x48000048UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_39 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_19 {
private:
    const CRegister m_register { 0x4800004cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_32 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_20 {
private:
    const CRegister m_register { 0x48000050UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_95 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_21 {
private:
    const CRegister m_register { 0x48000054UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_99 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_22 {
private:
    const CRegister m_register { 0x48000058UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_15 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_23 {
private:
    const CRegister m_register { 0x4800005cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_23 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_24 {
private:
    const CRegister m_register { 0x48000060UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_38 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_25 {
private:
    const CRegister m_register { 0x48000064UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_22 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_26 {
private:
    const CRegister m_register { 0x48000068UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_52 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_27 {
private:
    const CRegister m_register { 0x4800006cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_5 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_28 {
private:
    const CRegister m_register { 0x48000070UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_29 {
private:
    const CRegister m_register { 0x48000074UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_85 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_30 {
private:
    const CRegister m_register { 0x48000078UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_71 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_31 {
private:
    const CRegister m_register { 0x4800007cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_38 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_32 {
private:
    const CRegister m_register { 0x48000080UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_55 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_33 {
private:
    const CRegister m_register { 0x48000084UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_88 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_34 {
private:
    const CRegister m_register { 0x48000088UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_47 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_35 {
private:
    const CRegister m_register { 0x4800008cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_53 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_36 {
private:
    const CRegister m_register { 0x48000090UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_95 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_37 {
private:
    const CRegister m_register { 0x48000094UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_71 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_38 {
private:
    const CRegister m_register { 0x48000098UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_83 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_39 {
private:
    const CRegister m_register { 0x4800009cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_21 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_40 {
private:
    const CRegister m_register { 0x480000a0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_41 {
private:
    const CRegister m_register { 0x480000a4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_56 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_42 {
private:
    const CRegister m_register { 0x480000a8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_94 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_43 {
private:
    const CRegister m_register { 0x480000acUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_55 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_44 {
private:
    const CRegister m_register { 0x480000b0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_28 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_45 {
private:
    const CRegister m_register { 0x480000b4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_46 {
private:
    const CRegister m_register { 0x480000b8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_36 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_47 {
private:
    const CRegister m_register { 0x480000bcUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_74 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_48 {
private:
    const CRegister m_register { 0x480000c0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_84 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_49 {
private:
    const CRegister m_register { 0x480000c4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_25 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_50 {
private:
    const CRegister m_register { 0x480000c8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_32 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_51 {
private:
    const CRegister m_register { 0x480000ccUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_60 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_52 {
private:
    const CRegister m_register { 0x480000d0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_72 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_53 {
private:
    const CRegister m_register { 0x480000d4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_57 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_54 {
private:
    const CRegister m_register { 0x480000d8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_55 {
private:
    const CRegister m_register { 0x480000dcUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_23 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_56 {
private:
    const CRegister m_register { 0x480000e0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_63 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_57 {
private:
    const CRegister m_register { 0x480000e4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_5 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_58 {
private:
    const CRegister m_register { 0x480000e8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_1 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_59 {
private:
    const CRegister m_register { 0x480000ecUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_26 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_60 {
private:
    const CRegister m_register { 0x480000f0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_87 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_61 {
private:
    const CRegister m_register { 0x480000f4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_94 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_62 {
private:
    const CRegister m_register { 0x480000f8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_23 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_63 {
private:
    const CRegister m_register { 0x480000fcUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_21 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_64 {
private:
    const CRegister m_register { 0x48000100UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_85 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_65 {
private:
    const CRegister m_register { 0x48000104UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_80 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_66 {
private:
    const CRegister m_register { 0x48000108UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_13 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_67 {
private:
    const CRegister m_register { 0x4800010cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_82 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_68 {
private:
    const CRegister m_register { 0x48000110UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_82 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_69 {
private:
    const CRegister m_register { 0x48000114UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_99 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_70 {
private:
    const CRegister m_register { 0x48000118UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_67 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_71 {
private:
    const CRegister m_register { 0x4800011cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_74 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_72 {
private:
    const CRegister m_register { 0x48000120UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_31 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_73 {
private:
    const CRegister m_register { 0x48000124UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_91 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_74 {
private:
    const CRegister m_register { 0x48000128UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_47 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_75 {
private:
    const CRegister m_register { 0x4800012cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_46 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_76 {
private:
    const CRegister m_register { 0x48000130UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_65 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_77 {
private:
    const CRegister m_register { 0x48000134UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_43 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_78 {
private:
    const CRegister m_register { 0x48000138UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_30 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_79 {
private:
    const CRegister m_register { 0x4800013cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_27 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_80 {
private:
    const CRegister m_register { 0x48000140UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_72 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_81 {
private:
    const CRegister m_register { 0x48000144UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_1 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_82 {
private:
    const CRegister m_register { 0x48000148UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_30 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_83 {
private:
    const CRegister m_register { 0x4800014cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_70 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_84 {
private:
    const CRegister m_register { 0x48000150UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_79 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_85 {
private:
    const CRegister m_register { 0x48000154UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_69 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_86 {
private:
    const CRegister m_register { 0x48000158UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_44 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_87 {
private:
    const CRegister m_register { 0x4800015cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_15 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_88 {
private:
    const CRegister m_register { 0x48000160UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_78 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_89 {
private:
    const CRegister m_register { 0x48000164UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_90 {
private:
    const CRegister m_register { 0x48000168UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_20 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_91 {
private:
    const CRegister m_register { 0x4800016cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_4 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_92 {
private:
    const CRegister m_register { 0x48000170UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_32 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_93 {
private:
    const CRegister m_register { 0x48000174UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_94 {
private:
    const CRegister m_register { 0x48000178UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_18 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_95 {
private:
    const CRegister m_register { 0x4800017cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_64 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_96 {
private:
    const CRegister m_register { 0x48000180UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_88 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_97 {
private:
    const CRegister m_register { 0x48000184UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_75 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_98 {
private:
    const CRegister m_register { 0x48000188UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_17 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_99 {
private:
    const CRegister m_register { 0x4800018cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_51 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_100 {
private:
    const CRegister m_register { 0x48000190UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_12 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_101 {
private:
    const CRegister m_register { 0x48000194UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_38 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_102 {
private:
    const CRegister m_register { 0x48000198UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_2 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_103 {
private:
    const CRegister m_register { 0x4800019cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_54 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_104 {
private:
    const CRegister m_register { 0x480001a0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_24 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_105 {
private:
    const CRegister m_register { 0x480001a4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_54 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_106 {
private:
    const CRegister m_register { 0x480001a8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_58 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_107 {
private:
    const CRegister m_register { 0x480001acUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_3 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_108 {
private:
    const CRegister m_register { 0x480001b0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_58 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_109 {
private:
    const CRegister m_register { 0x480001b4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_58 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_110 {
private:
    const CRegister m_register { 0x480001b8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_21 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_111 {
private:
    const CRegister m_register { 0x480001bcUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_77 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_112 {
private:
    const CRegister m_register { 0x480001c0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_67 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_113 {
private:
    const CRegister m_register { 0x480001c4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_50 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_114 {
private:
    const CRegister m_register { 0x480001c8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_7 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_115 {
private:
    const CRegister m_register { 0x480001ccUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_65 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_116 {
private:
    const CRegister m_register { 0x480001d0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_27 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_117 {
private:
    const CRegister m_register { 0x480001d4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_84 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_118 {
private:
    const CRegister m_register { 0x480001d8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_73 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_119 {
private:
    const CRegister m_register { 0x480001dcUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_71 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_120 {
private:
    const CRegister m_register { 0x480001e0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_121 {
private:
    const CRegister m_register { 0x480001e4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_10 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_122 {
private:
    const CRegister m_register { 0x480001e8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_49 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_123 {
private:
    const CRegister m_register { 0x480001ecUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_55 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_124 {
private:
    const CRegister m_register { 0x480001f0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_95 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_125 {
private:
    const CRegister m_register { 0x480001f4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_28 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_126 {
private:
    const CRegister m_register { 0x480001f8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_62 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_127 {
private:
    const CRegister m_register { 0x480001fcUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_77 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_128 {
private:
    const CRegister m_register { 0x48000200UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_14 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_129 {
private:
    const CRegister m_register { 0x48000204UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_22 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_130 {
private:
    const CRegister m_register { 0x48000208UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_70 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_131 {
private:
    const CRegister m_register { 0x4800020cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_20 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_132 {
private:
    const CRegister m_register { 0x48000210UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_94 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_133 {
private:
    const CRegister m_register { 0x48000214UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_82 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_134 {
private:
    const CRegister m_register { 0x48000218UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_98 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_135 {
private:
    const CRegister m_register { 0x4800021cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_72 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_136 {
private:
    const CRegister m_register { 0x48000220UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_1 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_137 {
private:
    const CRegister m_register { 0x48000224UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_5 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_138 {
private:
    const CRegister m_register { 0x48000228UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_76 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_139 {
private:
    const CRegister m_register { 0x4800022cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_29 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_140 {
private:
    const CRegister m_register { 0x48000230UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_7 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_141 {
private:
    const CRegister m_register { 0x48000234UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_142 {
private:
    const CRegister m_register { 0x48000238UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_56 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_143 {
private:
    const CRegister m_register { 0x4800023cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_92 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_144 {
private:
    const CRegister m_register { 0x48000240UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_51 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_145 {
private:
    const CRegister m_register { 0x48000244UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_83 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_146 {
private:
    const CRegister m_register { 0x48000248UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_39 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_147 {
private:
    const CRegister m_register { 0x4800024cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_39 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_148 {
private:
    const CRegister m_register { 0x48000250UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_39 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_149 {
private:
    const CRegister m_register { 0x48000254UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_65 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_150 {
private:
    const CRegister m_register { 0x48000258UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_92 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_151 {
private:
    const CRegister m_register { 0x4800025cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_90 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_152 {
private:
    const CRegister m_register { 0x48000260UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_153 {
private:
    const CRegister m_register { 0x48000264UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_67 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_154 {
private:
    const CRegister m_register { 0x48000268UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_91 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_155 {
private:
    const CRegister m_register { 0x4800026cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_60 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_156 {
private:
    const CRegister m_register { 0x48000270UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_20 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_157 {
private:
    const CRegister m_register { 0x48000274UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_99 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_158 {
private:
    const CRegister m_register { 0x48000278UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_54 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_159 {
private:
    const CRegister m_register { 0x4800027cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_67 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_160 {
private:
    const CRegister m_register { 0x48000280UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_2 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_161 {
private:
    const CRegister m_register { 0x48000284UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_25 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_162 {
private:
    const CRegister m_register { 0x48000288UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_77 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_163 {
private:
    const CRegister m_register { 0x4800028cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_43 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_164 {
private:
    const CRegister m_register { 0x48000290UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_11 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_165 {
private:
    const CRegister m_register { 0x48000294UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_61 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_166 {
private:
    const CRegister m_register { 0x48000298UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_7 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_167 {
private:
    const CRegister m_register { 0x4800029cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_49 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_168 {
private:
    const CRegister m_register { 0x480002a0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_169 {
private:
    const CRegister m_register { 0x480002a4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_14 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_170 {
private:
    const CRegister m_register { 0x480002a8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_54 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_171 {
private:
    const CRegister m_register { 0x480002acUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_67 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_172 {
private:
    const CRegister m_register { 0x480002b0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_22 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_173 {
private:
    const CRegister m_register { 0x480002b4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_24 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_174 {
private:
    const CRegister m_register { 0x480002b8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_37 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_175 {
private:
    const CRegister m_register { 0x480002bcUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_176 {
private:
    const CRegister m_register { 0x480002c0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_51 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_177 {
private:
    const CRegister m_register { 0x480002c4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_26 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_178 {
private:
    const CRegister m_register { 0x480002c8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_97 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_179 {
private:
    const CRegister m_register { 0x480002ccUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_46 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_180 {
private:
    const CRegister m_register { 0x480002d0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_64 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_181 {
private:
    const CRegister m_register { 0x480002d4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_34 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_182 {
private:
    const CRegister m_register { 0x480002d8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_48 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_183 {
private:
    const CRegister m_register { 0x480002dcUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_56 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_184 {
private:
    const CRegister m_register { 0x480002e0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_44 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_185 {
private:
    const CRegister m_register { 0x480002e4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_82 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_186 {
private:
    const CRegister m_register { 0x480002e8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_2 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_187 {
private:
    const CRegister m_register { 0x480002ecUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_21 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_188 {
private:
    const CRegister m_register { 0x480002f0UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_9 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_189 {
private:
    const CRegister m_register { 0x480002f4UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_91 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_190 {
private:
    const CRegister m_register { 0x480002f8UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_91 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_191 {
private:
    const CRegister m_register { 0x480002fcUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 3);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_62 << (shift * 3);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_192 {
private:
    const CRegister m_register { 0x48000300UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 4);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_42 << (shift * 4);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_193 {
private:
    const CRegister m_register { 0x48000304UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_55 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_194 {
private:
    const CRegister m_register { 0x48000308UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 2);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_81 << (shift * 2);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_195 {
private:
    const CRegister m_register { 0x4800030cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_69 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_196 {
private:
    const CRegister m_register { 0x48000310UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_79 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_197 {
private:
    const CRegister m_register { 0x48000314UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_12 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_198 {
private:
    const CRegister m_register { 0x48000318UL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 1);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_26 << (shift * 1);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
        m_register.set(calculate_value(shift, val), calculate_bitmask(shift));
    }
};
class CREG_199 {
private:
    const CRegister m_register { 0x4800031cUL };

    inline std::uint32_t calculate_value (std::uint32_t shift, std::uint32_t val) {
        return val << (shift * 0);
    }

    inline std::uint32_t calculate_bitmask (std::uint32_t shift) {
        return CONST_66 << (shift * 0);
    }
public:
    inline void configure (std::uint32_t shift, std::uint32_t val) {
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
        {
            CREG_186 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_129 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_5_member_8 == ENUM_23_VAL_1) {
        __attribute__((unused)) ENUM_12 val = param->ST_5_member_1;
        __attribute__((unused)) uint8_t shift = param->ST_5_member_2;
        {
            CREG_199 reg {};
            reg.configure(shift, val);
        }
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
        {
            CREG_36 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_180 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_94 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_185 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_190 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_2_member_0 == ENUM_3_VAL_4) {
        __attribute__((unused)) ENUM_26 val = param->ST_2_member_5;
        __attribute__((unused)) ENUM_7 shift = param->ST_2_member_7;
        {
            CREG_53 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_51 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_150 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_71 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_2_member_6 == ENUM_8_VAL_2) {
        __attribute__((unused)) int val = param->ST_2_member_9;
        __attribute__((unused)) ENUM_7 shift = param->ST_2_member_7;
        {
            CREG_65 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_35 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_79 reg {};
            reg.configure(shift, val);
        }
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
        {
            CREG_98 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_123 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_132 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_19_member_2 == ENUM_8_VAL_0) {
        __attribute__((unused)) ENUM_25 val = param->ST_19_member_5;
        __attribute__((unused)) ENUM_25 shift = param->ST_19_member_5;
        {
            CREG_3 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_151 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_198 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_71 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_19_member_4 == ENUM_1_VAL_1) {
        __attribute__((unused)) ENUM_25 val = param->ST_19_member_5;
        __attribute__((unused)) ENUM_9 shift = param->ST_19_member_1;
        {
            CREG_143 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_144 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_186 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_37 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_167 reg {};
            reg.configure(shift, val);
        }
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
        {
            CREG_26 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_139 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_24 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_181 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_134 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_18_member_2 == ENUM_11_VAL_3) {
        __attribute__((unused)) ENUM_12 val = param->ST_18_member_6;
        __attribute__((unused)) ENUM_21 shift = param->ST_18_member_8;
        {
            CREG_58 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_5 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_164 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_18_member_6 == ENUM_12_VAL_6) {
        __attribute__((unused)) ENUM_23 val = param->ST_18_member_5;
        __attribute__((unused)) ENUM_14 shift = param->ST_18_member_1;
        {
            CREG_154 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_91 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_15 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_57 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_142 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_18_member_9 == ENUM_10_VAL_1) {
        __attribute__((unused)) ENUM_21 val = param->ST_18_member_8;
        __attribute__((unused)) ENUM_14 shift = param->ST_18_member_1;
        {
            CREG_132 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_126 reg {};
            reg.configure(shift, val);
        }
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
        {
            CREG_188 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_130 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_9_member_8 == ENUM_12_VAL_4) {
        __attribute__((unused)) ENUM_18 val = param->ST_9_member_2;
        __attribute__((unused)) ENUM_13 shift = param->ST_9_member_6;
        {
            CREG_144 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_75 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_194 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_9_member_8 == ENUM_12_VAL_2) {
        __attribute__((unused)) ENUM_12 val = param->ST_9_member_8;
        __attribute__((unused)) ENUM_8 shift = param->ST_9_member_5;
        {
            CREG_146 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_9_member_8 == ENUM_12_VAL_8) {
        __attribute__((unused)) ENUM_17 val = param->ST_9_member_3;
        __attribute__((unused)) ENUM_17 shift = param->ST_9_member_3;
        {
            CREG_82 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_153 reg {};
            reg.configure(shift, val);
        }
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
        {
            CREG_160 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_12 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_130 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_134 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_12_member_7 == ENUM_26_VAL_7) {
        __attribute__((unused)) ENUM_16 val = param->ST_12_member_5;
        __attribute__((unused)) ENUM_16 shift = param->ST_12_member_5;
        {
            CREG_94 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_12_member_3 == ENUM_15_VAL_3) {
        __attribute__((unused)) ENUM_28 val = param->ST_12_member_6;
        __attribute__((unused)) ENUM_26 shift = param->ST_12_member_7;
        {
            CREG_74 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_171 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_109 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_113 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_12_member_9 == ENUM_10_VAL_3) {
        __attribute__((unused)) ENUM_4 val = param->ST_12_member_2;
        __attribute__((unused)) ENUM_15 shift = param->ST_12_member_3;
        {
            CREG_114 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_135 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_98 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_142 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_158 reg {};
            reg.configure(shift, val);
        }
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
        {
            CREG_7 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_183 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_17_member_5 == ENUM_4_VAL_1) {
        __attribute__((unused)) ENUM_14 val = param->ST_17_member_2;
        __attribute__((unused)) ENUM_0 shift = param->ST_17_member_1;
        {
            CREG_62 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_150 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_13 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_17 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_17_member_2 == ENUM_14_VAL_0) {
        __attribute__((unused)) uint8_t val = param->ST_17_member_0;
        __attribute__((unused)) ENUM_28 shift = param->ST_17_member_3;
        {
            CREG_81 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_35 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_17_member_2 == ENUM_14_VAL_3) {
        __attribute__((unused)) ENUM_7 val = param->ST_17_member_4;
        __attribute__((unused)) uint8_t shift = param->ST_17_member_0;
        {
            CREG_9 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_56 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_95 reg {};
            reg.configure(shift, val);
        }
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
        {
            CREG_63 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_3_member_9 == ENUM_17_VAL_7) {
        __attribute__((unused)) ENUM_19 val = param->ST_3_member_3;
        __attribute__((unused)) uint8_t shift = param->ST_3_member_0;
        {
            CREG_59 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_33 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_171 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_95 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_199 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_3_member_5 == ENUM_1_VAL_2) {
        __attribute__((unused)) ENUM_28 val = param->ST_3_member_2;
        __attribute__((unused)) ENUM_19 shift = param->ST_3_member_3;
        {
            CREG_86 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_126 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_96 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_3_member_2 == ENUM_28_VAL_1) {
        __attribute__((unused)) ENUM_27 val = param->ST_3_member_4;
        __attribute__((unused)) ENUM_27 shift = param->ST_3_member_4;
        {
            CREG_55 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_111 reg {};
            reg.configure(shift, val);
        }
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
        {
            CREG_100 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_9_member_8 == ENUM_12_VAL_9) {
        __attribute__((unused)) ENUM_13 val = param->ST_9_member_6;
        __attribute__((unused)) ENUM_8 shift = param->ST_9_member_5;
        {
            CREG_45 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_49 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_9_member_8 == ENUM_12_VAL_9) {
        __attribute__((unused)) ENUM_21 val = param->ST_9_member_4;
        __attribute__((unused)) ENUM_13 shift = param->ST_9_member_6;
        {
            CREG_29 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_155 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_9_member_0 == ENUM_17_VAL_8) {
        __attribute__((unused)) ENUM_9 val = param->ST_9_member_9;
        __attribute__((unused)) int shift = param->ST_9_member_7;
        {
            CREG_190 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_136 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_52 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_44 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_181 reg {};
            reg.configure(shift, val);
        }
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
        {
            CREG_1 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_33 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_83 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_112 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_18_member_9 == ENUM_10_VAL_1) {
        __attribute__((unused)) ENUM_11 val = param->ST_18_member_2;
        __attribute__((unused)) ENUM_21 shift = param->ST_18_member_8;
        {
            CREG_105 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_94 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_88 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_168 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_54 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_18_member_8 == ENUM_21_VAL_0) {
        __attribute__((unused)) ENUM_23 val = param->ST_18_member_5;
        __attribute__((unused)) ENUM_9 shift = param->ST_18_member_0;
        {
            CREG_91 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_184 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_70 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_193 reg {};
            reg.configure(shift, val);
        }
    }
    if (param->ST_18_member_1 == ENUM_14_VAL_1) {
        __attribute__((unused)) ENUM_21 val = param->ST_18_member_8;
        __attribute__((unused)) ENUM_12 shift = param->ST_18_member_3;
        {
            CREG_37 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_24 reg {};
            reg.configure(shift, val);
        }
        {
            CREG_177 reg {};
            reg.configure(shift, val);
        }
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