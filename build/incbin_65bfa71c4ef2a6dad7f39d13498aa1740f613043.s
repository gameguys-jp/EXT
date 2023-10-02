.section .data.fountain_texture, "aw"
.balign 4

.global fountain_texture
.type fountain_texture, @object
.size fountain_texture, (fountain_texture_end - fountain_texture)
fountain_texture:
	.incbin "C:/Users/6120n/Downloads/PS1Game-master/PS1Game-master/textures/fountain_texture.tim"

.local fountain_texture_end
fountain_texture_end:

.balign 4

.section .data.fountain_texture_size, "aw"
.balign 4

.global fountain_texture_size
.type fountain_texture_size, @object
.size fountain_texture_size, 4
fountain_texture_size:
	.int (fountain_texture_end - fountain_texture)
