var 
	n,k,i:longint;
begin
	readln(n,k);
	for i:=1 to n do
		Begin
		if (i=1) then
			begin
				if (i mod k=0) then
				begin
				write('*');
				continue;
				end
				else
				begin
				write(i);
				end;
			end
			else
			begin
				if (i mod k=0) then
				begin
				write(' *');
				continue;
				end
				else
				begin
				write(' ',i);
				end;
			end;
		end;
	writeln;
end.