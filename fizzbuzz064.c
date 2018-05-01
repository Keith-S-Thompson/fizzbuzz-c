#include <stdio.h>

static void inc(int *i) {
    switch (*i) {
        case   '1': *i =   '2';  break;
        case   '2': *i =   '3';  break;
        case   '3': *i =   '4';  break;
        case   '4': *i =   '5';  break;
        case   '5': *i =   '6';  break;
        case   '6': *i =   '7';  break;
        case   '7': *i =   '8';  break;
        case   '8': *i =   '9';  break;
        case   '9': *i =  '10';  break;
        case  '10': *i =  '11';  break;
        case  '11': *i =  '12';  break;
        case  '12': *i =  '13';  break;
        case  '13': *i =  '14';  break;
        case  '14': *i =  '15';  break;
        case  '15': *i =  '16';  break;
        case  '16': *i =  '17';  break;
        case  '17': *i =  '18';  break;
        case  '18': *i =  '19';  break;
        case  '19': *i =  '20';  break;
        case  '20': *i =  '21';  break;
        case  '21': *i =  '22';  break;
        case  '22': *i =  '23';  break;
        case  '23': *i =  '24';  break;
        case  '24': *i =  '25';  break;
        case  '25': *i =  '26';  break;
        case  '26': *i =  '27';  break;
        case  '27': *i =  '28';  break;
        case  '28': *i =  '29';  break;
        case  '29': *i =  '30';  break;
        case  '30': *i =  '31';  break;
        case  '31': *i =  '32';  break;
        case  '32': *i =  '33';  break;
        case  '33': *i =  '34';  break;
        case  '34': *i =  '35';  break;
        case  '35': *i =  '36';  break;
        case  '36': *i =  '37';  break;
        case  '37': *i =  '38';  break;
        case  '38': *i =  '39';  break;
        case  '39': *i =  '40';  break;
        case  '40': *i =  '41';  break;
        case  '41': *i =  '42';  break;
        case  '42': *i =  '43';  break;
        case  '43': *i =  '44';  break;
        case  '44': *i =  '45';  break;
        case  '45': *i =  '46';  break;
        case  '46': *i =  '47';  break;
        case  '47': *i =  '48';  break;
        case  '48': *i =  '49';  break;
        case  '49': *i =  '50';  break;
        case  '50': *i =  '51';  break;
        case  '51': *i =  '52';  break;
        case  '52': *i =  '53';  break;
        case  '53': *i =  '54';  break;
        case  '54': *i =  '55';  break;
        case  '55': *i =  '56';  break;
        case  '56': *i =  '57';  break;
        case  '57': *i =  '58';  break;
        case  '58': *i =  '59';  break;
        case  '59': *i =  '60';  break;
        case  '60': *i =  '61';  break;
        case  '61': *i =  '62';  break;
        case  '62': *i =  '63';  break;
        case  '63': *i =  '64';  break;
        case  '64': *i =  '65';  break;
        case  '65': *i =  '66';  break;
        case  '66': *i =  '67';  break;
        case  '67': *i =  '68';  break;
        case  '68': *i =  '69';  break;
        case  '69': *i =  '70';  break;
        case  '70': *i =  '71';  break;
        case  '71': *i =  '72';  break;
        case  '72': *i =  '73';  break;
        case  '73': *i =  '74';  break;
        case  '74': *i =  '75';  break;
        case  '75': *i =  '76';  break;
        case  '76': *i =  '77';  break;
        case  '77': *i =  '78';  break;
        case  '78': *i =  '79';  break;
        case  '79': *i =  '80';  break;
        case  '80': *i =  '81';  break;
        case  '81': *i =  '82';  break;
        case  '82': *i =  '83';  break;
        case  '83': *i =  '84';  break;
        case  '84': *i =  '85';  break;
        case  '85': *i =  '86';  break;
        case  '86': *i =  '87';  break;
        case  '87': *i =  '88';  break;
        case  '88': *i =  '89';  break;
        case  '89': *i =  '90';  break;
        case  '90': *i =  '91';  break;
        case  '91': *i =  '92';  break;
        case  '92': *i =  '93';  break;
        case  '93': *i =  '94';  break;
        case  '94': *i =  '95';  break;
        case  '95': *i =  '96';  break;
        case  '96': *i =  '97';  break;
        case  '97': *i =  '98';  break;
        case  '98': *i =  '99';  break;
        case  '99': *i = '100';  break;
        case '100': *i = '101';  break;
    }
}

static void line(int i) {
    switch (i) {
        case '3': 
        case '6': 
        case '9': 
        case '12': 
        case '18': 
        case '21': 
        case '24': 
        case '27': 
        case '33': 
        case '36': 
        case '39': 
        case '42': 
        case '48': 
        case '51': 
        case '54': 
        case '57': 
        case '63': 
        case '66': 
        case '69': 
        case '72': 
        case '78': 
        case '81': 
        case '84': 
        case '87': 
        case '93': 
        case '96': 
        case '99':   puts("Fizz"); break;

        case '5': 
        case '10': 
        case '20': 
        case '25': 
        case '35': 
        case '40': 
        case '50': 
        case '55': 
        case '65': 
        case '70': 
        case '80': 
        case '85': 
        case '95': 
        case '100':   puts("Buzz"); break;

        case '15':
        case '30':
        case '45':
        case '60':
        case '75':
        case '90':  puts("FizzBuzz"); break;

        case '1':  puts("1");  break;
        case '2':  puts("2");  break;
        case '4':  puts("4");  break;
        case '7':  puts("7");  break;
        case '8':  puts("8");  break;
        case '11': puts("11"); break;
        case '13': puts("13"); break;
        case '14': puts("14"); break;
        case '16': puts("16"); break;
        case '17': puts("17"); break;
        case '19': puts("19"); break;
        case '22': puts("22"); break;
        case '23': puts("23"); break;
        case '26': puts("26"); break;
        case '28': puts("28"); break;
        case '29': puts("29"); break;
        case '31': puts("31"); break;
        case '32': puts("32"); break;
        case '34': puts("34"); break;
        case '37': puts("37"); break;
        case '38': puts("38"); break;
        case '41': puts("41"); break;
        case '43': puts("43"); break;
        case '44': puts("44"); break;
        case '46': puts("46"); break;
        case '47': puts("47"); break;
        case '49': puts("49"); break;
        case '52': puts("52"); break;
        case '53': puts("53"); break;
        case '56': puts("56"); break;
        case '58': puts("58"); break;
        case '59': puts("59"); break;
        case '61': puts("61"); break;
        case '62': puts("62"); break;
        case '64': puts("64"); break;
        case '67': puts("67"); break;
        case '68': puts("68"); break;
        case '71': puts("71"); break;
        case '73': puts("73"); break;
        case '74': puts("74"); break;
        case '76': puts("76"); break;
        case '77': puts("77"); break;
        case '79': puts("79"); break;
        case '82': puts("82"); break;
        case '83': puts("83"); break;
        case '86': puts("86"); break;
        case '88': puts("88"); break;
        case '89': puts("89"); break;
        case '91': puts("91"); break;
        case '92': puts("92"); break;
        case '94': puts("94"); break;
        case '97': puts("97"); break;
        case '98': puts("98"); break;
    }
}

int main(void) {
    for (int i = '1'; i != '101'; inc(&i)) {
        line(i);
    }
}
