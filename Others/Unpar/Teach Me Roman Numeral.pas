var
	msk,i,num,dgt,dummy:longint;
begin
readln(msk);
for dummy:=1 to msk do
	begin
	readln(num);
	if num=1000 then
		begin
		writeln('M');
		end
	else
		begin
		dgt:=(num div 100);
		num:=num-(dgt*100);
		if dgt>=5 then
			begin
			if dgt=9 then
				begin
				write('CM');
				end
			else
				begin
				write('D');
				for i:=6 to dgt do
					begin
					write('C');
					end;
				end;
			end;
		if dgt=4 then
			begin
			write('CD');
			end;
		if dgt<=3 then
			begin
			for i:=1 to dgt do
				begin
				write('C');
				end;
			end;
		dgt:=(num div 10);
		num:=num-(dgt*10);
		if dgt>=5 then
			begin
			if dgt=9 then
				begin
				write('XC');
				end
			else
				begin
				write('L');
				for i:=6 to dgt do
					begin
					write('X');
					end;
				end;
			end;
		if dgt=4 then
			begin
			write('XL');
			end;
		if dgt<=3 then
			begin
			for i:=1 to dgt do
				begin
				write('X');
				end;
			end;
		dgt:=(num div 1);
		if dgt>=5 then
			begin
			if dgt=9 then
				begin
				write('IX');
				end
			else
				begin
				write('V');
				for i:=6 to dgt do
					begin
					write('I');
					end;
				end;
			end;
		if dgt=4 then
			begin
			write('IV');
			end;
		if dgt<=3 then
			begin
			for i:=1 to dgt do
				begin
				write('I');
				end;
			end;
		writeln;
		end;
	end;
end.