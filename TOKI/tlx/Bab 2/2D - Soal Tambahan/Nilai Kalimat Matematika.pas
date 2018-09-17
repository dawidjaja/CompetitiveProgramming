var
	a,b,x:longint;
	sp,op:char;
begin
	readln(a, sp, op, sp, b);
	if op='+' then
		begin
		x:=a+b;
		writeln(x);
		end;
	if op='-' then
		begin
		x:=a-b;
		writeln(x);
		end;
	if op='*' then
		begin
		x:=a*b;
		writeln(x);
		end;
	if op='<' then
		begin
			if a<b then
			begin
			writeln('benar');
			end
		else
			begin
			writeln('salah')
			end;
		end;
	if op='>' then
		begin
			if a>b then
			begin
			writeln('benar');
			end
		else
			begin
			writeln('salah');
			end;
		end;
	if op='=' then
		begin
			if a=b then
			begin
			writeln('benar');
			end
		else
			begin
			writeln('salah');
			end;
		end;
end.