var
	list:array[0..10000] of string;
	a,first,n,x:longint;
begin
	readln(first);
	for x:=1 to first do
		begin
		readln(list[x]);
		end;
	for x:=1 to first do
		begin
		if list[x]='0' then
			begin
			writeln('0');
			end
		else
			begin
			for a:=length(list[x]) downto 1 do
				begin
				if (copy(list[x], a, 1)='0') then
				continue;
					begin
					for n:=a downto 1 do
						begin
						write(copy(list[x], n, 1));
						end;
					end;
				break;
				end;
			writeln;
			end;
		end;
end.