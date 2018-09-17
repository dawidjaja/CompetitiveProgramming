var
	msk,i,j,k:longint;
begin
	readln(msk);
	for i:=1 to msk do
	begin
		for j:=1 to msk-i do
		write(' ');
		for k:=1 to i do
		write('*') ;
		writeln;
	end
end.