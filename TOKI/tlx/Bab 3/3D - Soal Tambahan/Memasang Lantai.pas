var
	list:array[0..100000] of longint;
	msk,i:longint;
begin
	readln(msk);
	if msk<3 then
		begin
		writeln(1);
		end;
	if msk=3 then
		begin
		writeln(2);
		end;
	if msk>3 then
		begin
		list[1]:=1;
		list[2]:=1;
		list[3]:=2;
		for i:=4 to msk do
			begin
			list[i]:=(list[i-1] mod 1000000)+(list[i-3] mod 1000000);
			end;
		writeln(list[i] mod 1000000);
		end;
end.