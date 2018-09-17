var
	n,i:integer;
begin
	readln(n);
	for i :=1 to n do
	begin
		if (i=93) then
			begin
			writeln('ERROR');
			break;
			end;
		if(i mod 10=0) then
			continue;
			
			writeln(i);
	end;
end.