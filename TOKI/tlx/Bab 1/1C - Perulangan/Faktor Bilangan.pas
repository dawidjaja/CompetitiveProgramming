var
	n,j:longint;
begin
	readln(n);
	for j:=n downto 1 do
		begin
		if (n mod j=0) then
			begin
			write(j);
			writeln;
			end;
		end;
end.