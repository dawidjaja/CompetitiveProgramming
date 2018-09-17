var
	list:array[1..1000000] of longint;
	msk,i:longint;
	hsl:int64;
begin
	readln(msk);
	for i:=1 to msk do
		begin
		readln(list[i]);
		end;
	for i:=1 to msk do
		begin
		hsl:=list[i]*list[i];
		hsl:=hsl+1;
		hsl:=hsl*list[i];
		hsl:=hsl div 2;
		writeln(hsl);
		end;
end.