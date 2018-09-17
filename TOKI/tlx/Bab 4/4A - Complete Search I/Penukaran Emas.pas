var
	list:array[0..10000] of longint;
	msk,i:longint;
begin
	readln(msk);
	list[0]:=0;
	list[1]:=1;
	list[2]:=2;
	list[3]:=3;
	if msk>3 then
	begin
		for i:=4 to msk do
		begin
		if (list[i div 4]+list[i div 3]+list[i div 2])>i then
			begin
			list[i]:=(list[i div 4]+list[i div 3]+list[i div 2]);
			end
		else
			begin
			list[i]:=i;
			end;
		end;
	end;
	writeln(list[msk]);
end.