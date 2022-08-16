`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 12/16/2017 02:56:04 PM
// Design Name: 
// Module Name: MemoryModule
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


module MemoryModule(
    input logic clk,
    input logic reset, load,
    input logic [3:0] random,
    output logic [3:0] memory
);

logic loadDelay;
logic risingEdge;

assign risingEdge = load & ~loadDelay;

always_ff @(posedge clk)
    begin
        loadDelay <= load;
        if (reset)
            memory <= 4'b0;
        else if (risingEdge == 1)
            memory <= random;
        else
            memory <= memory;
    end

endmodule