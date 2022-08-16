module topStep(input clk,reset,change_player,output [3:0] phases);
		logic stop = 1;
		logic [1:0] speed;
		logic direction;
		logic change_player_int;
		logic [26:0] counter;
		localparam size = 10000;
		assign direction = 1;
		assign speed = 2'b01;
		pushButton changeButton(clk,reset,change_player,change_player_int);
		stepmotor motor(clk,direction,speed,phases,stop);
		always @(posedge clk)
		begin
			if(change_player_int == 1)
			begin
				stop <= 0;
				counter <= 0;
			end
			else
			begin
				if(counter != size)
					counter <= counter +1;
				else
					stop <= 1;
			end
		end
endmodule