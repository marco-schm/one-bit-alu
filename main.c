#include <stdbool.h>
#include <stdio.h>

typedef struct {
    bool sum;
    bool carry_out;
} AdderResult;

bool and_gate(bool input1, bool input2){
    return input1 && input2;
}

bool or_gate(bool input1, bool input2){
    return input1 || input2;
}

bool xor_gate(bool input1, bool input2){
    return input1 ^ input2;
}

bool inverter(bool input1, bool activate) {
    return xor_gate(input1,activate);
}

bool gate(bool input1, bool activate){
    return and_gate(input1, activate);
}

AdderResult adder(bool input1, bool input2, bool carry_in) {
    AdderResult result;
    result.sum = input1 ^ input2 ^ carry_in;
    result.carry_out = (input1 && input2) | (carry_in && (input1 ^ input2));
    return result;
}

bool multiplexer(bool input1, bool input2, bool input3, bool input4, bool select1, bool select2){
    return (input1 && !select1 && !select2) || (input2 && select1 && !select2) ||
            (input3 && !select1 && select2) || (input4 && select1 && select2);

}


void print_alu_operations() {
    printf("Possible ALU Operations:\n");
    printf("  0: DEACTIVATE\n");
    printf("  1: A\n");
    printf("  2: NOT A\n");
    printf("  3: A AND B\n");
    printf("  4: A OR B\n");
    printf("  5: A XOR B\n");
    printf("  6: A + B\n");
    printf("  7: B - A\n");
}


int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: %s <value_for_a> <value_for_b> <alu_operation>\n", argv[0]);
        printf("  where:\n");
        printf("    <value_for_a> and <value_for_b> are either '0' or '1'\n");
        printf("    <alu_operation> is a number between 0 and 7\n");
        print_alu_operations();
        return 1;
    }

    bool a = (argv[1][0] == '1') ? true : false;
    bool b = (argv[2][0] == '1') ? true : false;

    bool f3;
    bool f2;
    bool f1;
    bool f0;

    switch (argv[3][0]) {
        case '0':
            //DEACTIVATE
            f3 = false;
            f2 = false;
            f1 = false;
            f0 = false;
            break;

        case '1':
            //A
            f3 = false;
            f2 = false;
            f1 = false;
            f0 = true;
            break;

        case '2':
            //NOT A
            f3 = true;
            f2 = false;
            f1 = false;
            f0 = true;
            break;

        case '3':
            //A_AND_B
            f3 = false;
            f2 = true;
            f1 = false;
            f0 = false;
            break;

        case '4':
            //A_OR_B;
            f3 = false;
            f2 = true;
            f1 = false;
            f0 = true;
            break;

        case '5':
            //A_XOR_B;
            f3 = false;
            f2 = true;
            f1 = true;
            f0 = false;
            break;

        case '6':
            //A_PLUS_B;
            f3 = false;
            f2 = true;
            f1 = true;
            f0 = true;
            break;

        case '7':
            //B_MINUS_A;
            f3 = true;
            f2 = true;
            f1 = true;
            f0 = true;
            break;

        default:
            printf("Invalid ALU operation: %s\n", argv[3]);
            print_alu_operations();
            return 1;
    }

    bool a1 = inverter(a, f3);
    bool b1 = gate(b, f2);
    bool and_result = and_gate(a1, b1);
    bool or_result = or_gate(a1, b1);
    bool xor_result = xor_gate(a1, b1);
    AdderResult adder_result = adder(a1, b1, f3);
    bool multiplexer_result = multiplexer(and_result, or_result, xor_result,
                                                  adder_result.sum, f0, f1);

    printf("R: %d, D: %d", multiplexer_result, adder_result.carry_out);
    return 0;

}