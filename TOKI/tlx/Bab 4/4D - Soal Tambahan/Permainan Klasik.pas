var
	msk,num,i:longint;
begin
readln(msk);
for i:=1 to msk do	
	begin
	readln(num);
	if (num mod 6)=0 then
		begin
		writeln('TIDAK');
		end
	else
		begin
		writeln('YA');
		end;
	end;
end.