var
	list:array[1..100,1..100] of integer;
	a,b,x,y,i,j:longint;
begin
	readln(x,y);
	for i:=1 to x do
		begin
		for j:=1 to y do
			begin
			read(list[i,j]);
			end;
		end;
	for b:=1 to y do
		begin
		for a:=x downto 1 do
			begin
			if a=1 then
				begin
				write(list[a,b]);
				end
			else
				begin
				write(list[a,b]);
				write(' ');
				end;
			end;
		writeln();
		end;
end.