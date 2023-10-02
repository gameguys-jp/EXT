.section .data._99bandwidth_face, "aw"
.balign 4

.global _99bandwidth_face
.type _99bandwidth_face, @object
.size _99bandwidth_face, (_99bandwidth_face_end - _99bandwidth_face)
_99bandwidth_face:
	.incbin "C:/Users/6120n/Downloads/PS1Game-master/PS1Game-master/textures/99bandwidth_face.tim"

.local _99bandwidth_face_end
_99bandwidth_face_end:

.balign 4

.section .data._99bandwidth_face_size, "aw"
.balign 4

.global _99bandwidth_face_size
.type _99bandwidth_face_size, @object
.size _99bandwidth_face_size, 4
_99bandwidth_face_size:
	.int (_99bandwidth_face_end - _99bandwidth_face)
