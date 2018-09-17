var
	a,b,c,d,e,f,x,y,temp:int64;
begin
	readln(a,b);
	readln(c,d);
	e:=((a*d)+(b*c));
	f:=(b*d);
	x:=e;
	y:=f;
	while y<>0 do
		begin
		temp:=y;
		y:=x mod y;
		x:=temp;
		end;
	e:=e div x;
	f:=f div x;
	writeln(e,' ',f);
end.