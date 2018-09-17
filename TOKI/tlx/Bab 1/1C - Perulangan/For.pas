var
	jbil,i,jml:longint;
begin
	jml:=0;
	read(jbil);
	
	for i:=1 to jbil do
	begin
		read(jbil);
		jml:=jml+jbil;
	end;
	writeln(jml);
end.