.section .data.cobble, "aw"
.balign 4

.global cobble
.type cobble, @object
.size cobble, (cobble_end - cobble)
cobble:
	.incbin "C:/Users/6120n/Downloads/PS1Game-master/PS1Game-master/textures/cobble.tim"

.local cobble_end
cobble_end:

.balign 4

.section .data.cobble_size, "aw"
.balign 4

.global cobble_size
.type cobble_size, @object
.size cobble_size, 4
cobble_size:
	.int (cobble_end - cobble)
