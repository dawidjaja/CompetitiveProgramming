var
	hsl,msk,i:longint;
begin
	readln(msk);
	hsl:=0;
	for i:=1 to msk do
		begin
		hsl:=hsl+(i*i);
		end;
	writeln(hsl);
end.