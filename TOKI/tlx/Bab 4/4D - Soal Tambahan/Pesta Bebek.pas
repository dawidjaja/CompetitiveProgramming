var
	list:array[0..1500] of string;
	msk,i,j,k:longint;
	text,sk:string;
begin
	readln(msk);
	readln(text);
	list[1]:=lowercase(text);
	writeln(1);
	for i:=2 to msk do
		begin
		readln(text);
		sk:=lowercase(text);
		for j:=(i-1) downto 1 do
			begin
			if sk>list[j] then
				begin
				if j=i-1 then
					begin
					list[i]:=sk;
					writeln(i);
					break;
					end
				else
					begin
					for k:=i-1 downto j+1 do
						begin
						list[k+1]:=list[k];
						end;
					list[j+1]:=sk;
					writeln(j+1);
					break;
					end;
				end
			else
				begin
					if j=1 then
					begin
					for k:=i-1 downto 1 do
						begin
						list[k+1]:=list[k];
						end;
					list[1]:=sk;
					writeln(1);
					end;
				end;
			end;
		end;
end.