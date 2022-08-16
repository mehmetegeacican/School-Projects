module inputCapture(input clk,reset,sw_in,output logic sw_out);
logic sw_inold = 1;
always @(posedge clk)
	begin
		if(reset)
			sw_out <= 0;
		else
		begin
		sw_inold <= sw_in;
		if(sw_inold == 1 && sw_in == 0)
			sw_out <= 1;
		else
			sw_out <= 0;
		end			
	end
endmodule