.section .data._00bandwidth_face, "aw"
.balign 4

.global _00bandwidth_face
.type _00bandwidth_face, @object
.size _00bandwidth_face, (_00bandwidth_face_end - _00bandwidth_face)
_00bandwidth_face:
	.incbin "C:/Users/6120n/Downloads/PS1Game-master/PS1Game-master/textures/00bandwidth_face.tim"

.local _00bandwidth_face_end
_00bandwidth_face_end:

.balign 4

.section .data._00bandwidth_face_size, "aw"
.balign 4

.global _00bandwidth_face_size
.type _00bandwidth_face_size, @object
.size _00bandwidth_face_size, 4
_00bandwidth_face_size:
	.int (_00bandwidth_face_end - _00bandwidth_face)
