var
	text:ansistring;
	a:longint;
begin
	readln(text);
	for a:=length(text) downto 1 do
		begin
		write(copy(text, a, 1));
		end;
	writeln;
end.