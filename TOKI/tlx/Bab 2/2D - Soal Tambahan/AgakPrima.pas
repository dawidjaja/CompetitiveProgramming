var
	list:array[1..8] of longint;
	msk,i,temp,x:longint;
begin
	readln(msk);
	for i:=1 to msk do
		begin
			readln(list[i]);
		end;
	for i:=1 to msk do
		begin
		if list[i]<1 then
			begin
			writeln('TIDAK');
			end
		else
			begin
			temp:=0;
			for x:=1 to list[i] do
				begin
				if list[i] mod x =0 then
					begin
					temp:=temp+1;
					if temp>4 then
						begin
						writeln('TIDAK');
						break;
						end;
					end; 
				end;
				if temp<5 then
					begin
					writeln('YA');
					end;
			end;
		end;
end.