var
	x:real;
begin
	readln(x);
	if (x>0) then
	begin
	writeln (trunc(x),' ',trunc(x+1));
	end
	else
	if (x<0) then
	begin
	writeln (trunc(x-1),' ',trunc(x));
	end
end.