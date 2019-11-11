// [GonBee]
// �f�[�^���`�����N�ɕ�������B

#ifndef CHUNK_HPP
#define CHUNK_HPP

#include <cinttypes>
#include <cstring>

template <size_t D, size_t C> size_t chunk_size(uint8_t seq);
template <size_t D, size_t C> void get_chunk(void* chu, const void* dat, uint8_t seq);
template <size_t D, size_t C> void set_chunk(void* dat, const void* chu, uint8_t seq);

// �`�����N�̃T�C�Y���擾����B
template <
	size_t D, // �f�[�^�̃T�C�Y�B
	size_t C  // �`�����N�̍ő�T�C�Y�B
> size_t // �擾�����`�����N�̃T�C�Y�B
chunk_size(
	uint8_t seq // �V�[�P���X�B
) {
	size_t top = C * seq;
	if (top + C > D) return D - top;
	else return C;
}

// �`�����N���擾����B
template <
	size_t D, // �f�[�^�̃T�C�Y�B
	size_t C  // �`�����N�̍ő�T�C�Y�B
> void get_chunk(
	void* chu,       // �`�����N�B
	const void* dat, // �f�[�^�B
	uint8_t seq      // �V�[�P���X�B
) {
	std::memcpy(chu, dat + C * seq, chunk_size(seq));
}

// �`�����N��ݒ肷��B
template <
	size_t D, // �f�[�^�̃T�C�Y�B
	size_t C  // �`�����N�̍ő�T�C�Y�B
> void set_chunk(
	void* dat,       // �f�[�^�B
	const void* chu, // �`�����N�B
	uint8_t seq      // �V�[�P���X�B
) {
	std::memcpy(dat + C * seq, chu, chunk_size(seq));
}

#endif
