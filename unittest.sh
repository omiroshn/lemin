#!/bin/sh

maps=(	
		maps/empty \
		maps/empty_line \
		maps/no_ants \
		maps/several_starts \
		maps/no_start_found \
		maps/less_coords \
		maps/much_coords \
		maps/bigL \
		maps/repeating_name \
		maps/repeating_coords \
	)

if echo "$*" | grep -e '-s' > /dev/null
then
	for map in ${maps[*]}
	do
		if ./lem-in < $map | grep 'ERROR:' > /dev/null;
			then printf "%s: OK\n" "$map";
			else printf "%s: KO\n" "$map";
		fi
	done
else
	for map in ${maps[*]}
	do
		if ./lem-in < $map | grep 'ERROR:' > /dev/null;
			then echo "OK";
			else echo "KO";
		fi
	done
fi