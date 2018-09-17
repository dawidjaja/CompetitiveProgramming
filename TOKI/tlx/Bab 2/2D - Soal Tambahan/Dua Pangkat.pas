var
	msk:real;
begin
	readln(msk);
	while msk>1 do
		begin
		msk:=(msk/2);
		end;
	if msk=1 then
		begin
		writeln('TRUE');
		end;
	if msk<1 then
		begin
		writeln('FALSE');
		end;
end.