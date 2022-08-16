module scoreCalculate(clk,reset,inc_rp,inc_lp,dec_rp,dec_lp,left_score_low,left_score_high, right_score_low,right_score_high);
input clk;
input reset;
input inc_rp,inc_lp,dec_rp,dec_lp;
output logic [3:0]left_score_high;
output logic [3:0]left_score_low;
output logic [3:0]right_score_high;
output logic [3:0]right_score_low;
always @(posedge clk)
begin
	if(reset)
	begin
	left_score_low <= 0;
	right_score_low <= 0;
	right_score_high <= 0;
	left_score_high <= 0;
	end
	else
	begin
	if(inc_rp == 1)
	begin
		if(right_score_low < 10)
			right_score_low <= right_score_low + 1;
		if(right_score_low == 9)
		begin
			right_score_low <= 0;
			if(right_score_high == 9)
				right_score_high <= 0;
			else
				right_score_high <= right_score_high + 1;
		end
	end
	if(inc_lp == 1)
		if(left_score_low < 10)
			left_score_low <= left_score_low + 1;
		if(left_score_low == 9)
		begin
			left_score_low <= 0;
			if(left_score_high == 9)
				left_score_high <= 0;
			else
				left_score_high <= left_score_high + 1;
		end
	if(dec_rp == 1)
		if(right_score_low > 0)
			right_score_low <= right_score_low - 1;
		if(right_score_low == 0)
		begin
			right_score_low <= 9;
			if(right_score_high ==  0)
				right_score_low <= 9;
			else
			right_score_high <= right_score_high - 1;
		end
	if(dec_lp == 1)
		if(left_score_low > 0)
			left_score_low <= left_score_low - 1;
		if(left_score_low == 0)
		begin
			left_score_low <= 9;
			if(left_score_high == 0)
				left_score_low <= 9;
			else
				left_score_high <= left_score_high - 1;
		end
	end
end
endmodule