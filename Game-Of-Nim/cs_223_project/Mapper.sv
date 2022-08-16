`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/14/2017 10:00:08 AM
// Design Name: 
// Module Name: Mapper
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module Mapper(
    input clk,
    input logic [3:0]motorValue,
    output logic [3:0]changedValue
    );
    /*
    */
 always_comb
    begin
        case(motorValue)
        /*D*/    4'b0000: changedValue <= 4'b0000; //
        /*#*/    4'b0001: changedValue <= 4'b0001; //
        /*0*/    4'b0010: changedValue <= 4'b0010; //
        /***/    4'b0011: changedValue <= 4'b0011; //
        /*C*/    4'b0100: changedValue <= 4'b0100; //
        /*9*/    4'b0101: changedValue <= 4'b0101; //
        /*8*/    4'b0110: changedValue <= 4'b0110; //
        /*7*/    4'b0111: changedValue <= 4'b0111; //
        /*B*/    4'b1000: changedValue <= 4'b1000; //
        /*6*/    4'b1001: changedValue <= 4'b1001; //
        /*5*/    4'b1010: changedValue <= 4'b1010; //
        /*4*/    4'b1011: changedValue <= 4'b1011; //
        /*A*/    4'b1100: changedValue <= 4'b1100; //
        /*3*/    4'b1101: changedValue <= 4'b1101; //
        /*2*/    4'b1110: changedValue <= 4'b1110; //
        /*1*/    4'b1111: changedValue <= 4'b1111; //
        /**/    default: changedValue <= 4'b0000;
       endcase
   end
endmodule
