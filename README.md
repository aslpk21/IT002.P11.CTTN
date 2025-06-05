# Attribute-Based Encryption (ABE) kết hợp với AES

## Tổng quan
ABE (Attribute-Based Encryption) là một hệ thống mã hóa sử dụng các thuộc tính để kiểm soát quyền truy cập. Kết hợp với AES, ABE bảo vệ khóa AES bằng cách mã hóa nó dựa trên chính sách thuộc tính. Chỉ người dùng có đủ thuộc tính thỏa mãn chính sách mới có thể giải mã khóa AES và truy cập dữ liệu.

### Thành phần chính
- **Nhóm**: 
  - \( G_1, G_2 \): Hai nhóm cyclic cấp \( p \).
  - \( G_T \): Nhóm đích.
  - \( g_1 \in G_1, g_2 \in G_2 \): Phần tử sinh.
- **Ánh xạ song tuyến tính**: 
  - \( e: G_1 \times G_2 \rightarrow G_T \).
  - Tính chất: \( e(g_1^a, g_2^b) = e(g_1, g_2)^{ab} \).
- **Khóa hệ thống**:
  - **Public Key (PK)**: \( (g_1, g_2, e(g_1, g_2)^\alpha, H) \), với \( H \) là hàm hash ánh xạ thuộc tính vào \( G_2 \).
  - **Master Key (MK)**: \( \alpha \in \mathbb{Z}_p \) (chỉ người có quyền cao nhất biết).

### Ciphertext
Người dùng nhận **Ciphertext (CT)**:
- \( C_0 = \text{AES_encrypt}(plaintext, K_{AES}) \): Dữ liệu được mã hóa bằng AES.
- \( \{C_i\} \): Các thành phần mã hóa cho từng thuộc tính \( attr_i \) trong chính sách, với \( C_i = H(attr_i)^{s_i} \).
- Chính sách: Ví dụ, "phải có \( attr_1 \) VÀ \( attr_2 \)".

## Khóa bí mật (SK)
Khi người dùng nhập tập thuộc tính \( \{attr_i\} \), server tạo khóa bí mật \( SK_i \) dựa trên \( g_1^\alpha \). Có nhiều cơ chế để tạo \( SK_i \), ví dụ như BWM7.

### Cấu trúc khóa bí mật
\[
SK = \left\{
  D = g_2^{\alpha + r},
  D_i = H(attr_i)^r \quad \text{for each } attr_i \text{ in Attributes}
\right\}
\]
- **Thành phần**:
  - \( \alpha \): Bí mật chính từ Master Key.
  - \( r \): Giá trị ngẫu nhiên riêng biệt cho mỗi user.
  - \( D \): Thành phần chung, kết hợp \( \alpha \) và \( r \).
  - \( D_i \): Thành phần riêng cho từng thuộc tính, dùng để pairing với \( C_i \).

### Ví dụ khóa bí mật
| User   | Thuộc tính         | \( r \) (ngẫu nhiên) |
|--------|--------------------|----------------------|
| Alice  | \{attr1, attr2\}   | 17                   |
| Bob    | \{attr1, attr2\}   | 53                   |
| Carol  | \{attr1, attr3\}   | 8                    |

## Hàm KeyGen
Hàm KeyGen tạo khóa bí mật cho người dùng dựa trên Master Key và thuộc tính.

```python
def KeyGen(MK, Attributes):
    # MK = (g2, α)
    α = MK['α']
    g2 = MK['g2']

    # 1. Sinh ngẫu nhiên r
    r = random_in_Zp()

    # 2. Tính phần chung
    D = g2 ** (α + r)

    # 3. Tính phần riêng cho từng thuộc tính
    D_i = {}
    for attr in Attributes:
        h = H(attr)     # ánh xạ thuộc tính → G2
        D_i[attr] = h ** r

    return { 'D': D, 'D_i': D_i }
```

## Quá trình giải mã
### Input
- **Khóa bí mật (SK)**:
  - \( D = g_2^{\alpha + r} \)
  - \( D_i = H(attr_i)^r \)
- **Ciphertext (CT)**:
  - \( C_0 = \text{AES_encrypt}(plaintext, K_{AES}) \)
  - \( \{C_i = H(attr_i)^{s_i}\} \), với \( s_i \) là các phần chia sẻ bí mật \( s \) (từ hàm Shamir Secret Sharing).
- **Mục tiêu**:
  - Phục hồi \( e(g_1, g_2)^{\alpha s} \) để lấy khóa AES:
    \[
    K_{AES} = Hash(e(g_1, g_2)^{\alpha s})
    \]
  - Dùng \( K_{AES} \) để giải mã \( C_0 \), lấy plaintext.

### Quy trình
1. **Tính pairing cho từng thuộc tính**:
   - Với mỗi \( attr_i \) thỏa chính sách:
     \[
     e(D_i, C_i) = e(H(attr_i)^r, H(attr_i)^{s_i}) = e(H(attr_i), H(attr_i))^{r s_i}
     \]

2. **Kết hợp pairing**:
   - Sử dụng hệ số trọng số \( \omega_i \) từ cây truy cập (access tree) hoặc Shamir Secret Sharing:
     \[
     \prod_i e(D_i, C_i)^{\omega_i} = e(g_1, g_2)^{r s}
     \]

3. **Khôi phục bí mật chung**:
   - Tính:
     \[
     e(D, g_1)^s = e(g_2^{\alpha + r}, g_1)^s = e(g_2, g_1)^{\alpha s} \cdot e(g_2, g_1)^{r s}
     \]
   - Dùng \( e(g_2, g_1)^{r s} \) từ bước 2 để tách lấy:
     \[
     e(g_2, g_1)^{\alpha s}
     \]

4. **Lấy khóa AES và giải mã**:
   - Tính:
     \[
     K_{AES} = Hash(e(g_2, g_1)^{\alpha s})
     \]
   - Dùng \( K_{AES} \) giải mã \( C_0 \):
     \[
     plaintext = \text{AES_decrypt}(C_0, K_{AES})
     \]

### Pseudocode giải mã
```python
def decrypt(SK, CT, policy):
    # SK = { D, D_i dict }
    # CT = { C_0, C_i dict }
    # policy: cây truy cập

    # 1. Lấy các thuộc tính thỏa policy
    attrs = get_satisfying_attributes(SK, policy)
    
    # 2. Tính e(D_i, C_i) cho từng thuộc tính
    pairings = {}
    for attr in attrs:
        pairings[attr] = pairing(SK['D_i'][attr], CT['C_i'][attr])
    
    # 3. Lấy hệ số trọng số omega_i theo cây truy cập
    omega = get_weights(policy, attrs)
    
    # 4. Kết hợp các pairing với omega_i
    prod = 1
    for attr in attrs:
        prod *= pairings[attr] ** omega[attr]
    
    # 5. Tính e(D, g1)^s
    e_D_g1_s = compute_e_D_g1_s(SK['D'], CT)
    
    # 6. Lấy e(g2, g1)^{alpha s} = e(D, g1)^s / prod
    shared_secret = e_D_g1_s / prod
    
    # 7. Lấy khóa AES
    K_AES = Hash(shared_secret)
    
    # 8. Dùng K_AES giải mã C_0
    plaintext = AES_decrypt(CT['C_0'], K_AES)
    return plaintext
```

## Tại sao cần tính chất song tuyến tính của \( e \)?
Tính chất \( e(g_1^a, g_2^b) = e(g_1, g_2)^{ab} \) là cốt lõi vì:
1. **Kết nối khóa bí mật và thuộc tính**:
   - \( D_i = H(attr_i)^r \in G_2 \), \( C_i = H(attr_i)^{s_i} \in G_2 \).
   - \( e(D_i, C_i) \) tạo ra \( e(g_1, g_2)^{r s_i} \), liên kết \( r \) (từ SK) và \( s_i \) (từ CT).
2. **Phục hồi bí mật**:
   - Kết hợp các \( e(D_i, C_i)^{\omega_i} \) để lấy \( e(g_1, g_2)^{r s} \).
   - Dùng \( e(D, g_1)^s \) để tách \( e(g_1, g_2)^{\alpha s} \), lấy khóa AES.
3. **Bảo mật**:
   - Chỉ người có đủ thuộc tính mới tạo đúng \( e(g_1, g_2)^{r s} \), dựa trên bài toán Bilinear Diffie-Hellman.

## Vai trò của \( g_1 \), \( g_2 \)
- **\( g_1 \in G_1 \)**: Dùng để tính \( e(D, g_1)^s \), góp phần khôi phục \( e(g_2, g_1)^{\alpha s} \).
- **\( g_2 \in G_2 \)**: Dùng để tạo \( D = g_2^{\alpha + r} \) và \( C_i = H(attr_i)^{s_i} \).

## Kết luận
- **\( s \)**: Bí mật ngẫu nhiên do server chọn để tạo \( \{s_i\} \) (qua Shamir Secret Sharing) và mã hóa khóa AES.
- **Quá trình giải mã**: Dùng \( SK \), \( CT \), và pairing để khôi phục \( K_{AES} \), rồi giải mã dữ liệu.
- **Tính song tuyến tính**: Cho phép kết nối \( \alpha \), \( r \), và \( s \) để khôi phục bí mật chung một cách bảo mật.
