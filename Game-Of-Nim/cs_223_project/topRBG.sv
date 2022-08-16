`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Hamzeh Ahangari
// 
// Create Date: 
// Design Name: 
// Module Name: top
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision: 
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////

module topRBG(
	input clk, //100Mhz on Basys3
	input reset,
	input row_1,row_2,row_3,row_4,
	input newGame,
	// FPGA pins for 8x8 display
	output reset_out, //shift register's reset
	output OE, 	//output enable, active low 
	output SH_CP,  //pulse to the shift register
	output ST_CP,  //pulse to store shift register
	output DS, 	//shift register's serial input data
	output [7:0] col_select // active column, active high

	);
    
logic [2:0] col_num;

// initial value for RGB images:
//	image_???[0]     : left column  .... image_???[7]     : right column
//	image_???[?]'MSB : top line     .... image_???[?]'LSB : bottom line
logic [0:7] [7:0] image_red = 
{8'b00000000, 8'b00000000, 8'b00111000, 8'b00111000, 8'b00001000, 8'b00000100, 8'b11111110, 8'b11111110};
logic [0:7] [7:0]  image_green = 
{8'b00000000, 8'b00000000, 8'b00000000, 8'b00000000, 8'b0000000, 8'b00000000, 8'b00000000, 8'b00000000};
logic [0:7] [7:0]  image_blue = 
{8'b00001000, 8'b00001000, 8'b00000000, 8'b00000000, 8'b01111100, 8'b01111100, 8'b01000000, 8'b10000000};
logic newgame_out;
inputCapture newGameInputCapture(clk,reset,newGame,newgame_out);
logic row_1_out,row_2_out,row_3_out,row_4_out;
pushButton pr1(clk,reset,row_1,row_1_out);
pushButton pr2(clk,reset,row_2,row_2_out);
pushButton pr3(clk,reset,row_3,row_3_out);
pushButton pr4(clk,reset,row_4,row_4_out);
   
// This module displays 8x8 image on LED display module. 
display_8x8 display_8x8_0(
	.clk(clk),
	
	// RGB data for display current column
	.red_vect_in(image_red[col_num]),
	.green_vect_in(image_green[col_num]),
	.blue_vect_in(image_blue[col_num]),
	
	.col_data_capture(), // unused
	.col_num(col_num),
	
	// FPGA pins for display
	.reset_out(reset_out),
	.OE(OE),
	.SH_CP(SH_CP),
	.ST_CP(ST_CP),
	.DS(DS),
	.col_select(col_select)   
);
 logic [3:0] row_2_counter = 2;
 logic [3:0] row_3_counter = 1;
 logic [3:0] row_4_counter = 0;
// move the image to right every half a second to make an animation
always@ (posedge clk)
begin
	if ( row_1_out == 1 )
	begin
		image_blue[0][3] <= 0;
		image_blue[1][3] <= 0;
	end
	
	if(row_2_out == 1 && row_2_counter < 5)
	begin
		image_red[2][row_2_counter] <= 0;
		image_red[3][row_2_counter] <= 0;
		row_2_counter <= row_2_counter + 1;
	end
	if(row_3_out == 1 && row_3_counter < 6)
	begin
		image_blue[4][row_3_counter] <= 0;
		image_blue[5][row_3_counter] <= 0;
		row_3_counter <= row_3_counter +1;
	end
	if(row_4_out == 1 && row_4_counter < 7)
	begin 
		image_red[6][row_4_counter] <= 0;
		image_red[7][row_4_counter] <= 0;
		row_4_counter <= row_4_counter + 1;
	end
	if(newgame_out == 1)
	begin
		row_2_counter = 2;
		row_3_counter = 1;
		row_4_counter = 0;
		image_red ={8'b00000000, 8'b00000000, 8'b00111000, 8'b00111000, 8'b00001000, 8'b00000100, 8'b11111110, 8'b11111110};
		image_green ={8'b00000000, 8'b00000000, 8'b00000000, 8'b00000000, 8'b0000000, 8'b00000000, 8'b00000000, 8'b00000000};
		image_blue ={8'b00001000, 8'b00001000, 8'b00000000, 8'b00000000, 8'b01111100, 8'b01111100, 8'b01000000, 8'b10000000};
	end
end

endmodule




