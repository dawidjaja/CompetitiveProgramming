var
	bil:longint;
	jum:longint;
begin
	jum:=0;
	while not eof(input) do
	begin
	readln(bil);
	jum := jum+bil;
	end;
	writeln(jum);
end.