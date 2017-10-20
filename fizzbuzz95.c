#include <stdio.h>

static void Fizz(void) { puts("Fizz"); }
static void Buzz(void) { puts("Buzz"); }
static void FizzBuzz(void) { puts("FizzBuzz"); }
static void n1(void) { puts("1"); }
static void n2(void) { puts("2"); }
static void n4(void) { puts("4"); }
static void n7(void) { puts("7"); }
static void n8(void) { puts("8"); }
static void n11(void) { puts("11"); }
static void n13(void) { puts("13"); }
static void n14(void) { puts("14"); }
static void n16(void) { puts("16"); }
static void n17(void) { puts("17"); }
static void n19(void) { puts("19"); }
static void n22(void) { puts("22"); }
static void n23(void) { puts("23"); }
static void n26(void) { puts("26"); }
static void n28(void) { puts("28"); }
static void n29(void) { puts("29"); }
static void n31(void) { puts("31"); }
static void n32(void) { puts("32"); }
static void n34(void) { puts("34"); }
static void n37(void) { puts("37"); }
static void n38(void) { puts("38"); }
static void n41(void) { puts("41"); }
static void n43(void) { puts("43"); }
static void n44(void) { puts("44"); }
static void n46(void) { puts("46"); }
static void n47(void) { puts("47"); }
static void n49(void) { puts("49"); }
static void n52(void) { puts("52"); }
static void n53(void) { puts("53"); }
static void n56(void) { puts("56"); }
static void n58(void) { puts("58"); }
static void n59(void) { puts("59"); }
static void n61(void) { puts("61"); }
static void n62(void) { puts("62"); }
static void n64(void) { puts("64"); }
static void n67(void) { puts("67"); }
static void n68(void) { puts("68"); }
static void n71(void) { puts("71"); }
static void n73(void) { puts("73"); }
static void n74(void) { puts("74"); }
static void n76(void) { puts("76"); }
static void n77(void) { puts("77"); }
static void n79(void) { puts("79"); }
static void n82(void) { puts("82"); }
static void n83(void) { puts("83"); }
static void n86(void) { puts("86"); }
static void n88(void) { puts("88"); }
static void n89(void) { puts("89"); }
static void n91(void) { puts("91"); }
static void n92(void) { puts("92"); }
static void n94(void) { puts("94"); }
static void n97(void) { puts("97"); }
static void n98(void) { puts("98"); }

static void print(void (*p)(void)) {
    p();
}

int main(void) {
    print(n1);
    print(n2);
    print(Fizz);
    print(n4);
    print(Buzz);
    print(Fizz);
    print(n7);
    print(n8);
    print(Fizz);
    print(Buzz);
    print(n11);
    print(Fizz);
    print(n13);
    print(n14);
    print(FizzBuzz);
    print(n16);
    print(n17);
    print(Fizz);
    print(n19);
    print(Buzz);
    print(Fizz);
    print(n22);
    print(n23);
    print(Fizz);
    print(Buzz);
    print(n26);
    print(Fizz);
    print(n28);
    print(n29);
    print(FizzBuzz);
    print(n31);
    print(n32);
    print(Fizz);
    print(n34);
    print(Buzz);
    print(Fizz);
    print(n37);
    print(n38);
    print(Fizz);
    print(Buzz);
    print(n41);
    print(Fizz);
    print(n43);
    print(n44);
    print(FizzBuzz);
    print(n46);
    print(n47);
    print(Fizz);
    print(n49);
    print(Buzz);
    print(Fizz);
    print(n52);
    print(n53);
    print(Fizz);
    print(Buzz);
    print(n56);
    print(Fizz);
    print(n58);
    print(n59);
    print(FizzBuzz);
    print(n61);
    print(n62);
    print(Fizz);
    print(n64);
    print(Buzz);
    print(Fizz);
    print(n67);
    print(n68);
    print(Fizz);
    print(Buzz);
    print(n71);
    print(Fizz);
    print(n73);
    print(n74);
    print(FizzBuzz);
    print(n76);
    print(n77);
    print(Fizz);
    print(n79);
    print(Buzz);
    print(Fizz);
    print(n82);
    print(n83);
    print(Fizz);
    print(Buzz);
    print(n86);
    print(Fizz);
    print(n88);
    print(n89);
    print(FizzBuzz);
    print(n91);
    print(n92);
    print(Fizz);
    print(n94);
    print(Buzz);
    print(Fizz);
    print(n97);
    print(n98);
    print(Fizz);
    print(Buzz);
}
