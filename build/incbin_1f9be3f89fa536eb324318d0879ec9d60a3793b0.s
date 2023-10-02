.section .data.bandwidth_face, "aw"
.balign 4

.global bandwidth_face
.type bandwidth_face, @object
.size bandwidth_face, (bandwidth_face_end - bandwidth_face)
bandwidth_face:
	.incbin "C:/Users/6120n/Downloads/PS1Game-master/PS1Game-master/textures/bandwidth_face.tim"

.local bandwidth_face_end
bandwidth_face_end:

.balign 4

.section .data.bandwidth_face_size, "aw"
.balign 4

.global bandwidth_face_size
.type bandwidth_face_size, @object
.size bandwidth_face_size, 4
bandwidth_face_size:
	.int (bandwidth_face_end - bandwidth_face)
