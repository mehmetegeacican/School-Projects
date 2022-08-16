module Game(
input clk,
input reset,
input inc_rp,
input inc_lp,
input dec_rp,
input dec_lp,
input change_player,
input row_1,
input row_2,
input row_3,
input row_4,
input newgame,
output reset_out, //shift register's reset
output OE, 	//output enable, active low 
output SH_CP,  //pulse to the shift register
output ST_CP,  //pulse to store shift register
output DS, 	//shift register's serial input data
output [7:0] col_select, // active column, active high
output a,
output b,
output c,
output d,
output e,
output f,
output g,
output [3:0] an,
output [3:0] phases
);
	topRBG rbg(clk,reset,row_1,row_2,row_3,row_4,newGame,reset_out,OE,SH_CP,ST_CP,DS,col_select);
	topStep step(clk,reset,change_player,phases);
	topScoreBoard scoreBoard(clk,reset,inc_rp,inc_lp,dec_rp,dec_lp,a,b,c,d,e,f,g,an);
	
endmodule