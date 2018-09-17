var
	lol:array[0..25000] of longint;
	i,j:longint;
begin
	i:=0;
	while not eof do
		begin
		i:=i+1;
		readln(lol[i]);
		end;
		for j:=i downto 1 do
		begin
		writeln(lol[j]);
		end;
end.