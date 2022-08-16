module pushButton(input clk,reset,pb_in, output logic pb_out);
	logic pb_in_buf1,pb_in_buf2,pb_in_buf3;
	logic pb_int;
	always @(posedge clk)
	begin
		pb_in_buf3 <= pb_in_buf2;
		pb_in_buf2 <= pb_in_buf1;
		pb_in_buf1 <= pb_in;
	end
	
	always @(posedge clk)
	begin
		if(reset)
		begin
			pb_int <= 0;
			pb_out <= 0;
		end
		else
		begin
			pb_int <= pb_in_buf3;
		if(pb_int == 0 && pb_in_buf3 == 1)
			pb_out <= 1;
		else
			pb_out <= 0;
		end
	end
	
	endmodule