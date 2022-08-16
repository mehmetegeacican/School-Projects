`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/14/2017 09:59:23 AM
// Design Name: 
// Module Name: Comparator
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


module Comparator(
    input logic clk,
    input logic reset, 
    input logic keyValid,
    input logic [3:0]inValue,
    input logic [3:0]motorValue,
    output logic a, b, c, d, e, f, g,                  
    output logic dp,
    output logic [3:0]an
    );
    
    logic equal;
    logic [3:0]in0;
    logic [3:0]in1, in2, in3;
    assign in1 = 4'b0; 
    assign in2 = 4'b0; 
    assign in3 = 4'b0;    
    
    //comparator
    assign equal = ~(inValue[0] ^ motorValue[0]) & ~(inValue[1] ^ motorValue[1]) & ~(inValue[2] ^ motorValue[2]) & ~(inValue[3] ^ motorValue[3]);
    
    always_ff@(posedge clk)
        begin
            if(reset)
                in0 <= 4'b0;
            else if(keyValid == 1)
                begin
                    if(equal == 1)
                        if(in0 == 4'b1001)
                            in0 <= 0;
                        else
                            in0 <= in0 + 1;
                    else
                        if(in0 == 4'b0)
                            in0 <= in0;
                        else
                            in0 <= in0 - 1;
                end
             else
                in0 <= in0;
         end
        
            
      SevSeg_4digit display(.clk(clk),
                 .in3(in3), .in2(in2), .in1(in1), .in0(in0), 
                 .a(a), .b(b), .c(c), .d(d), .e(e), .f(f), .g(g), .dp(dp), 
                 .an(an));
                 
endmodule