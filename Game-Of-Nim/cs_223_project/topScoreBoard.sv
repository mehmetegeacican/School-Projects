module topScoreBoard(input clk,reset,inc_rp,inc_lp,dec_rp,dec_lp,output a,b,c,d,e,f,g,[3:0] an);
logic [3:0] left_score_high_int;
logic [3:0] right_score_high_int;
logic [3:0] left_score_low_int;
logic [3:0] right_score_low_int;
logic inc_rp_out,inc_lp_out,dec_rp_out,dec_lp_out;
inputCapture IncRp(clk,reset,inc_rp,inc_rp_out);
inputCapture IncLp(clk,reset,inc_lp,inc_lp_out);
inputCapture DecLp(clk,reset,dec_lp,dec_lp_out);
inputCapture DecRp(clk,reset,dec_rp,dec_rp_out);

scoreCalculate calculator(clk,reset,inc_rp_out,inc_lp_out,dec_rp_out,dec_lp_out,left_score_low_int,left_score_high_int, right_score_low_int,right_score_high_int);

SevSeg_4digit sevSeg(clk,right_score_low_int,right_score_high_int,left_score_low_int,left_score_high_int,a,b,c,d,e,f,g, an);

endmodule