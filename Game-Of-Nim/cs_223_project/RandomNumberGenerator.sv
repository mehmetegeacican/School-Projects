`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/14/2017 10:00:39 AM
// Design Name: 
// Module Name: RandomNumberGenerator
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


module RandomNumberGenerator(
    input logic reset,
    input logic clk,
    output logic [3:0]movement
    );
    
    logic feedback;
    logic [15:0]register;
    assign feedback = register[15] ^ register[14] ^ register[12] ^ register[2];
    
    always_ff@(posedge clk)
    begin
        if(reset)
            register <= 16'h0001;
        else
            register <= {register[14:0], feedback};
    end
    
    assign movement = register[3:0];
endmodule
